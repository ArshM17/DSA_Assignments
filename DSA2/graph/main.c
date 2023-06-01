#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "graph.h"

int main(int argc, char* argv[]){
	system("clear");
	if(!argv[1]) {
		printf("Text file required as command line argument\n");
		return 0;
	}
	FILE* file = fopen(argv[1],"r");
	if(!file){
		printf("File not found\n");
		return 0;
	}
	int vertexCount;
	fscanf(file, "%d", &vertexCount);
	int** matrix = NULL;
	createAdjacencyMatrix(&matrix, file, vertexCount);
	fclose(file);
	displayGraph(matrix, vertexCount);
//	displayVertexDegrees(matrix, vertexCount);
//	printf("%d ",isAdjacent(matrix,0,4));
	int count = countComponents(matrix,vertexCount);	
	return 0;
}
