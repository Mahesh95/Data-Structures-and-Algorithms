#include <iostream>
#include "graph.h"

using namespace std;

int main(){
	Graph graph(5);
	graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);

    graph.stronglyConnectedComponents();

	return 0;
}