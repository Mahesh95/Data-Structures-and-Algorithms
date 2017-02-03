#include <iostream>
#include "graph.h"
#include "minheap.h"
#include "compareFn.h"

using namespace std;

DijkstraHelperNode* dijkstra(Graph graph, int sourceNode);
int indexOf(int destination, DijkstraHelperNode *array, int size);

int main(){

	Graph graph(5);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(2, 1, 2);
    graph.addEdge(2, 3, 4);
    graph.addEdge(1, 4, 4);
    graph.addEdge(3, 4, 4);

    DijkstraHelperNode *resultArray = dijkstra(graph, 0);

    for(int i = 0; i < graph.getNumberOfVertices(); i++){
    	cout << resultArray[i].getDestination() << "----" << resultArray[i].getMinDistance() << endl;
    }
	return 0;
}

DijkstraHelperNode* dijkstra(Graph graph, int sourceNode){
	DijkstraHelperNode *resultArray = new DijkstraHelperNode[graph.getNumberOfVertices()];
	int resultArraySize = 0;

	int heapSize = graph.getNumberOfVertices();
	Heap<DijkstraHelperNode> priorityQueue(heapSize);

	// enqueue the source node
	DijkstraHelperNode firstNode(0);
	firstNode.setMinDistance(0);

	priorityQueue.enqueue(firstNode);

	while(!priorityQueue.isEmpty()){
		DijkstraHelperNode node = priorityQueue.dequeue();
		resultArray[resultArraySize++] = node;

		//enqueue all the neighbours not in the queue and update the weights of those already in the queue
		struct adjListNode* ptr = graph.getAdjList()[node.getDestination()].head;
		while(ptr){
			// if the node is not in the queue, enqueue it with the weight
			if(indexOf(ptr->destination, resultArray, resultArraySize) == -1){
				int destination = ptr->destination; 
				DijkstraHelperNode neighbourNode(destination);
				int distance = node.getMinDistance() + ptr->weight;
				neighbourNode.setMinDistance(distance);
				priorityQueue.enqueue(neighbourNode);
			}else{
				int newDistance = node.getMinDistance() + ptr->weight;
				if(newDistance < resultArray[indexOf(ptr->destination, resultArray, resultArraySize)].getMinDistance()){
					resultArray[indexOf(ptr->destination, resultArray, resultArraySize)].setMinDistance(newDistance);	
				}
			}

			ptr = ptr->next;
		}
	}

	return resultArray;
}

// returns the index of the destination node in the resultArray

int indexOf(int destination, DijkstraHelperNode *array, int size){
	
	for(int i = 0; i < size; i++){
		if(array[i].getDestination() == destination){
			return i;
		}
	}

	return -1;
}