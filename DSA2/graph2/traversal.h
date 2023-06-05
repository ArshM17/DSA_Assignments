#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include"adjacencyList.h"

void dfs(int vertex, graph* g);

void bfs(int vertex, graph* g);

graph minimumSpanningTreeOf(graph* g, int startVertex);

#endif
