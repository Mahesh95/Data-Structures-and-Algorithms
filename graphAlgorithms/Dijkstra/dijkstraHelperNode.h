#ifndef DIJKSTRAHELPERNODE_H
#define DIJKSTRAHELPERNODE_H

//the result of dijkstra will be stored as an array of dijkstraHelperNode
class DijkstraHelperNode{
private:
	int destination;
	int minDistance;

public:
	bool equals(DijkstraHelperNode& node);
	DijkstraHelperNode();
	DijkstraHelperNode(int destination);
	void setMinDistance(int distance);
	int getMinDistance();
	int getDestination();

};

bool DijkstraHelperNode::equals(DijkstraHelperNode& node){
	return (this->destination == node.destination);
}

DijkstraHelperNode::DijkstraHelperNode(){
	this->destination = -1;
	this->minDistance = 6600;
}

DijkstraHelperNode::DijkstraHelperNode(int destination){
	this->destination = destination;
	this->minDistance = 0;
}

void DijkstraHelperNode::setMinDistance(int distance){
	this->minDistance = distance;
}

int DijkstraHelperNode::getMinDistance(){
	return this->minDistance;
}

int DijkstraHelperNode::getDestination(){
	return this->destination;
}

#endif

