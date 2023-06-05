#include<stdio.h>
#include<stdlib.h>
#include"traversal.h"
#include"stack.h"
#include"queue.h"
#include"adjacencyList.h"

void dfs(int vertex, graph* g){
	stack s;
	int vertexCount = g->vertices;
	stackInit(&s, vertexCount);
	int* visited = calloc(vertexCount, sizeof(int));
	push(&s, vertex);
	//printf("%d ",vertex);
	visited[vertex] = 1;
	int currVertex;
	node* curr;
	while(!isEmptyS(&s)){
		currVertex = pop(&s);
		printf("%c\n",currVertex+97);
		curr = g->adjacencyList[currVertex];
		while(curr){
			if(visited[curr->data] != 1){
				push(&s, curr->data);
				//printf("%d ",curr->data);
				visited[curr->data] = 1;
			}
			curr = curr->next;
		}
	}
}

void bfs(int vertex, graph* g){
	queue q;
	int vertexCount = g->vertices;
	queueInit(&q, vertexCount);
	int* visited = calloc(vertexCount, sizeof(int));
	enqueue(&q, vertex);
	//printf("%d ",vertex);
	visited[vertex] = 1;
	int currVertex;
	node* curr;
	while(!isEmptyQ(&q)){
		currVertex = dequeue(&q);
		printf("%c\n",currVertex+97);
		curr = g->adjacencyList[currVertex];
		while(curr){
			if(visited[curr->data] != 1){
				enqueue(&q, curr->data);
				//printf("%d ",curr->data);
				visited[curr->data] = 1;
			}
			curr = curr->next;
		}
	}
}
