#include<stdlib.h>
#include<stdio.h>
#include"adjacencyList.h"

void initGraph(graph* g, int vertices){
	g->adjacencyList = malloc(sizeof(node*)*vertices);
	g->vertices = vertices;
	for(int i = 0;i<vertices;i++){
		g->adjacencyList[i] = NULL;
	}
}

void addEdge(graph* g, int parent, int vertex, int weight){
	node* curr = g->adjacencyList[parent];
	node* new = malloc(sizeof(node));
	new->data = vertex;
	new->weight = weight;
	new->next = NULL;
	//printf("%d ", parent);
	if(curr == NULL){
		g->adjacencyList[parent] = new;
		return;
	}
	while(curr->next){
		curr = curr->next;
	}
	curr->next = new;
}

void displayAdjacencyList(graph* g){	
	for(int i = 0;i<g->vertices;i++){
		node* curr = g->adjacencyList[i];
       		while(curr){
        		printf("%d ",curr->data);
                        curr = curr->next;
                }
                printf("\n");
	}
}
