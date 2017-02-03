
#include "dijkstraHelperNode.h"

#ifndef COMPAREFN_H
#define COMPAREFN_H
bool isGreater(DijkstraHelperNode node1, DijkstraHelperNode node2){
	return (node1.getMinDistance() > node2.getMinDistance());
}

void setVal(DijkstraHelperNode& node, int newVal){
	node.setMinDistance(newVal);
}

#endif