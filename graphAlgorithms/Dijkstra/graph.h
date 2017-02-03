
#include <iostream>
using namespace std;

struct adjListNode{
	int destination;
	int weight;

	struct adjListNode *next;
};

struct adjList{
	struct adjListNode *head;
};

struct adjListNode* createNode(int destination, int weight){
	struct adjListNode *node = new adjListNode();
	
	node->destination = destination;
	node->weight = weight;
	node->next = NULL;

	return node;
}

//directed weighted graph

class Graph{
private:
	int noOfVertices;
	adjList *array;
	void DFSutil(int sourceVertex, bool* visited);

public:
	Graph(int noOfVertices);
	void addEdge(int sourceVertex, int destinationVertex, int weight);
	void DFS();
	int getNumberOfVertices();
	adjList* getAdjList();
};


Graph::Graph(int noOfVertices){
	this->noOfVertices = noOfVertices;
	this->array = new adjList[noOfVertices];

	for(int i = 0; i < noOfVertices; i++){
		array[i].head = NULL;
	}
};

int Graph::getNumberOfVertices(){
	return this->noOfVertices;
}

adjList* Graph::getAdjList(){
	return this->array;
}

void Graph::addEdge(int sourceVertex, int destinationVertex, int weight){

	try{

		if(sourceVertex >= this->noOfVertices || destinationVertex >= this->noOfVertices){
			throw "invalid edge";
		}

		struct adjListNode *newNode = createNode(destinationVertex, weight);

		newNode->next = this->array[sourceVertex].head;
		this->array[sourceVertex].head = newNode;

	}catch(const char* msg){

		cout << msg << endl;

	}
	
}

void Graph::DFSutil(int sourceVertex, bool *visited){
	
	if(visited[sourceVertex]){
		return;
	}

	visited[sourceVertex] = true;

	cout << sourceVertex << endl;

	struct adjListNode *ptr = this->array[sourceVertex].head;

	while(ptr){
		DFSutil(ptr->destination, visited);
		ptr = ptr->next;
	}

}

void Graph::DFS(){

	bool visited[this->noOfVertices];
	
	for(int i = 0; i < this->noOfVertices; i++){
		visited[i] = false;
	}

	for(int i = 0; i < this->noOfVertices; i++){
		if(!visited[i]){
			DFSutil(i, visited);
		}
	}
}
