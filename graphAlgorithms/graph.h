/*
* File : graph.h
* Stores the graph class and and implementations of some graph algorithms
* Author: Mahesh
*/	

#ifndef GRAPH_H
#define GRAPH_H

#include <stack>

struct AdjListNode{
	int destination;
	struct AdjListNode* next;
};

struct AdjList{
	struct AdjListNode* head;
};

class Graph{

	private:

		int noOfVertices;
		struct AdjList* listArray;

		void DFSTraversal(int sourceNode, bool *visited);
		void topologicalSortUtil(int sourceNode, bool *visited, std::stack<int> &Stack);
		void DFSOnReversedGraph(std::stack<int> &Stack);
		void DFSOnReversedGraphUtil(int sourceNode, bool *visited, AdjList *revArray);

	public:

		Graph(int noOfVertices);

		void DFS();

		void addEdge(int source, int destination);

		void topologicalSort();

		void stronglyConnectedComponents();
				
};

void Graph::addEdge(int source, int destination){
	struct AdjListNode* newNode = new AdjListNode();
	newNode->destination = destination;

	/* inserting the node at the begining of the adjacency list of source node
	*  Graph is assumed to be directed
	*/
	newNode->next = this->listArray[source].head;
	this->listArray[source].head = newNode;
}


Graph::Graph(int noOfVertices){
	this->noOfVertices = noOfVertices;
	this->listArray = new AdjList[noOfVertices];

	for(int i = 0; i < noOfVertices; i++){
		this->listArray[i].head = NULL; 
	}
}

void Graph::DFS(){
	bool visited[this->noOfVertices];

	for(int i = 0; i < this->noOfVertices; i++){
		visited[i] = false;
	}
	// outer loop is significant in case there are components in graph
	for(int i = 0; i < this->noOfVertices; i++){
		if(!visited[i]){
			DFSTraversal(i, visited);
		}
	}
}

void Graph::DFSTraversal(int sourceNode, bool *visited){
	
	if(visited[sourceNode]){
		return;
	}

	visited[sourceNode] = true;

	std::cout << sourceNode << std::endl;

	// this pointer will be used to traverse all the neighbours of node i
	struct AdjListNode* neighbourPointer = this->listArray[sourceNode].head;

	while(neighbourPointer != NULL){
		DFSTraversal(neighbourPointer->destination, visited);
		neighbourPointer = neighbourPointer->next;
	}

}

/*
* Function: topologicalSort()
* sorts the nodes in topological order
*/

void Graph::topologicalSort(){
	bool visited[this->noOfVertices];
	std::stack<int> Stack;

	for(int i = 0; i < this->noOfVertices; i++){
		visited[i] = false;
	}

	for(int i = 0; i < this->noOfVertices; i++){
		if(!visited[i]){
			topologicalSortUtil(i, visited, Stack);
		}
	}


	// print contents of stack to obtain topological ordering
	while(!Stack.empty()){
		std::cout << Stack.top() << std::endl;
		Stack.pop();
	}
}

void Graph::topologicalSortUtil(int sourceNode, bool *visited, std::stack<int> &Stack){
	if(visited[sourceNode]){
		return;
	}

	visited[sourceNode] = true;

	struct AdjListNode* neighbourPointer = this->listArray[sourceNode].head;

	while(neighbourPointer != NULL){
		topologicalSortUtil(neighbourPointer->destination, visited, Stack);
		neighbourPointer = neighbourPointer->next;
	}

	Stack.push(sourceNode);
}


/*
*  Function: stronglyConnectedComponents() 
*  The function prints SCC of the graph in separate lines
*/
void Graph::stronglyConnectedComponents(){
	std::stack<int> Stack;
	bool visited[this->noOfVertices];

	for(int i = 0; i < this->noOfVertices; i++){
		visited[i] = false;
	}

	/* first order the graph nodes in decreasing order of finish time
	*  then call dfsutil on the reversed graph
	*/

	for(int i = 0; i < this->noOfVertices; i++){
		topologicalSortUtil(i, visited, Stack);
	}

	DFSOnReversedGraph(Stack);
}

/*
*  Function: DFSOnReversedGraph(Stack)
*  prints the strongly connected components of graph in separate lines
*/

void Graph::DFSOnReversedGraph(std::stack<int> &Stack){

	bool visited[this->noOfVertices];
	for(int i = 0; i < this->noOfVertices; i++){
		visited[i] = false;
	}

	AdjList *revArray = new AdjList[this->noOfVertices];
	for(int i = 0; i < this->noOfVertices; i++){
		revArray[i].head = NULL;
	}

	for(int i = 0; i < this->noOfVertices; i++){
		AdjListNode *ptr = this->listArray[i].head;

		while(ptr != NULL){
			AdjListNode *newNode = new AdjListNode();
			newNode->destination = i;
			newNode->next = revArray[ptr->destination].head;
			revArray[ptr->destination].head = newNode;

			ptr = ptr->next;
		}
	}

	while(!Stack.empty()){
		int vertex = Stack.top();
		
		if(!visited[vertex]){
			DFSOnReversedGraphUtil(vertex, visited, revArray);
			std::cout << std::endl;
		}

		Stack.pop();
		visited[vertex] = true;
	}
}

void Graph::DFSOnReversedGraphUtil(int sourceNode, bool *visited, AdjList *revArray){
	
	if(visited[sourceNode]){
		return;
	}

	visited[sourceNode] = true;

	std::cout << sourceNode << " ";

	AdjListNode *ptr = revArray[sourceNode].head;

	while(ptr != NULL){
		DFSOnReversedGraphUtil(ptr->destination, visited, revArray);
		ptr = ptr->next;
	}
}

#endif
