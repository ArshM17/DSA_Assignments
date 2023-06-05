#include<stdio.h>
#include"adjacencyList.h"
#include"traversal.h"
int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Give file as input\n");
		return 0;
	}
	FILE* f = fopen(argv[1],"r");
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

	//bfs(0, &g);
	dfs(0, &g);
	
	//graph minST = minimumSpanningTreeOf(&g, 0);
	//displayAdjacencyList(&minST);	
	return 0;
}
