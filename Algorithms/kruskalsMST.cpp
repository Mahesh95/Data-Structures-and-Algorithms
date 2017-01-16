#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int src,dst;
	int weight;
};

struct Graph{
	int noOfVertices,noOfEdges;
	struct Edge* edges;
};

struct Subset{
	int parent;
	int rank;
};

struct Graph* createGraph(int noOfVertices, int noOfEdges){
	struct Graph* graph = new Graph();
	graph->noOfVertices = noOfVertices;
	graph->noOfEdges = noOfEdges;
	graph->edges = new Edge[noOfEdges];

	return graph;
};

int find(struct Subset *subsets, int i){
	if(subsets[i].parent == i){
		return subsets[i].parent;
	}else{
		return find(subsets,subsets[i].parent);
	}
}

void unionSets(struct Subset* subsets, int x, int y){
	int xSet = find(subsets,x);
	int ySet = find(subsets,y);

	if(subsets[xSet].rank > subsets[ySet].rank){
		subsets[ySet].parent = xSet;
		subsets[xSet].rank += subsets[ySet].rank;
	}else{
		subsets[xSet].parent = ySet;
		subsets[ySet].rank += subsets[xSet].rank;
	}
}

int compareEdges(const void* a, const void* b){
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;

	return a1->weight > b1->weight;
}

void kruskalsMST(struct Graph* graph){
	int noOfVertices = graph->noOfVertices;
	struct Edge resultMST[noOfVertices-1];

	struct Subset* subsets = new Subset[noOfVertices];
	// create all singleton subsets
	for(int i = 0; i < noOfVertices; i++){
		subsets[i].rank = 1;
		subsets[i].parent = i;
	}

	// sort the edges by weight
	qsort(graph->edges, graph->noOfEdges, sizeof(graph->edges[0]), compareEdges);

	//now pick the edges with smallest weight if doesn't form a cycle with the current MST
	int k = 0;
	int i = 0;
	while(k < noOfVertices-1){
		struct Edge edge = graph->edges[i++];

		//if the picked edge doesn't form a cycle, add it to MST
		if(find(subsets, edge.src) != find(subsets, edge.dst)){
			resultMST[k++] = edge;
			unionSets(subsets,edge.src, edge.dst);
		}
	}

	//print MST
	for(i = 0; i < noOfVertices-1; i++){
		printf("%d---%d == %d\n",resultMST[i].src, resultMST[i].dst, resultMST[i].weight);
	}

	return;
}

int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
 
 
    // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dst = 1;
    graph->edges[0].weight = 10;
 
    // add edge 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dst = 2;
    graph->edges[1].weight = 6;
 
    // add edge 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dst = 3;
    graph->edges[2].weight = 5;
 
    // add edge 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dst = 3;
    graph->edges[3].weight = 15;
 
    // add edge 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dst = 3;
    graph->edges[4].weight = 4;
 
    kruskalsMST(graph);
 
    return 0;
}