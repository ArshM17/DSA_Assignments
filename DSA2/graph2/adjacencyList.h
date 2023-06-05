#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

typedef struct node{
	int data;
	struct node* next;
	int weight;
}node;

typedef struct graph{
	node** adjacencyList;
	int vertices;
}graph;

void initGraph(graph* g, int vertices);

void addEdge(graph* g, int parent, int vertex, int weight);

void displayAdjacencyList(graph* g);

#endif
