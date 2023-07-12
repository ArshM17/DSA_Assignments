#include<stdio.h>
#include<stdlib.h>
#include"traversal.h"
#include"stack.h"
#include"queue.h"
#include"adjacencyList.h"
#include"heap.h"

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

graph minimumSpanningTreeOf(graph* g, int startVertex){
	graph minST;
	initGraph(&minST, g->vertices);
	minHeap* heap = createMinHeap();
	node* curr;
	int* visited = calloc(g->vertices, sizeof(int));
	int visitedCount = 0;
	visited[startVertex] = 1;
	visitedCount++;
	curr = g->adjacencyList[startVertex];
	while(curr){
		insertNode(heap, curr);
		curr = curr->next;
	}
	//printf("%d ",heap->heapSize);
	while(visitedCount < g->vertices){
		curr = extractMin(heap);
		if(visited[curr->data] != 1){
			addEdge(&minST, curr->parent, curr->data, curr->weight);
			addEdge(&minST, curr->data, curr->parent, curr->weight);
			visited[curr->data] = 1;
			visitedCount++;
		}else{
			free(curr);
			continue;
		}
		curr = g->adjacencyList[curr->data];
		while(curr){
			if(visited[curr->data] != 1){
				insertNode(heap, curr);
			}
			curr = curr->next;
		}
	}
	return minST;
}

