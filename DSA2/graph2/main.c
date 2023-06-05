#include<stdio.h>
#include"adjacencyList.h"
#include"traversal.h"
int main(){
	FILE* f = fopen("file2","r");
	if(!f){
		printf("File not found!\n");
		return 0;
	}
	graph g;
	int vertexCount;
	fscanf(f, "%d", &vertexCount);
	initGraph(&g, vertexCount);
	int weight;
	for(int i = 0;i < vertexCount;i++){
		for(int j = 0;j < vertexCount;j++){
			fscanf(f, "%d", &weight);
			if(weight > 0){
				addEdge(&g, i, j, weight);
			}
		}
	}
	
	//displayAdjacencyList(&g);

	bfs(0, &g);
	dfs(0, &g);
	
	return 0;
}
