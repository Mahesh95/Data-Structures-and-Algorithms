#include <iostream>
#include "graph.h"
#include "minheap.h"
#include "compareFn.h"
#include "dijkstra.h"

using namespace std;

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