#ifndef DIJKSTRA_H
#define DIJKSTRA_H

DijkstraHelperNode* dijkstra(Graph graph, int sourceNode);

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

			int destination = ptr->destination;
			DijkstraHelperNode neighbourNode(destination);
			// if the neighbour is not in the queue, enqueue it with the weight
			if(priorityQueue.indexOf(neighbourNode) == -1){ 
				int distance = node.getMinDistance() + ptr->weight;
				neighbourNode.setMinDistance(distance);
				priorityQueue.enqueue(neighbourNode);
			}else{
				int newDistance = node.getMinDistance() + ptr->weight;
				if(newDistance < priorityQueue.getElementAt(priorityQueue.indexOf(neighbourNode)).getMinDistance()){
					priorityQueue.decreaseKey(priorityQueue.indexOf(neighbourNode), newDistance);
				}
			}

			ptr = ptr->next;
		}
	}

	return resultArray;
}

#endif