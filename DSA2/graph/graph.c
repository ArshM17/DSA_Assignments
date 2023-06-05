#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"

void createAdjacencyMatrix(int*** matrix_ptr, FILE* file, int vertexCount){
	*matrix_ptr = malloc(sizeof(int*) * vertexCount);
	int** matrix = *matrix_ptr;
	if(!matrix) return;
	int temp;
	for(int i = 0;i<vertexCount;i++){
		matrix[i] = malloc(sizeof(int)*vertexCount);
		if(!matrix[i]) return;
		for(int j = 0;j<vertexCount;j++){
			fscanf(file,"%d",&temp);
			if(temp == -1 || i==j){
				matrix[i][j] = INT_MIN;
			}else{
				matrix[i][j] = temp;
			}
		}
	}
}

void displayGraph(int** matrix, int vertexCount){
	printf("%8s","");
	for(int i = 0;i<vertexCount;i++){
		printf("%3s Vertex %d","",i);
	}
	printf("\n");
	for(int i = 0;i<vertexCount;i++){
		printf("Vertex %-2d",i);
		for(int j = 0;j<vertexCount;j++){
			printf("%11d ", matrix[i][j]);
		}	
		printf("\n");
	}
}

void displayVertexDegrees(int** matrix, int vertexCount){
	int degree;
	for(int i = 0;i<vertexCount;i++){
		degree = 0;
		for(int j = 0;j<vertexCount;j++){
			if(matrix[i][j]>=0) degree++;
		}
		printf("Vertex %d has a degree of %d\n",i,degree);
	}	
}

int isAdjacent(int** matrix, int a, int b){
	if(matrix[a][b] >= 0) return 1;
	return 0;
}

int countComponents(int** matrix,int vertexCount){
	int components = 0;
	int verticesInComponent;
	for(int i = 0;i<vertexCount;i++){
		if(matrix[i][i] == -2) continue;
		verticesInComponent = explore(&matrix, i, vertexCount);
		components++;
		printf("\nComponent %i has %d vertices\n",components,verticesInComponent);
	}
	return components;
}

int explore(int*** matrix, int vertex, int vertexCount){
	int** mat = *matrix;
	int count = 0;
	//-2 means vertex has been visited already so no need to explore again
	if(mat[vertex][vertex] == -2) return 0;
	for(int i = 0;i<vertexCount;i++){
		if(mat[vertex][i] == -2) continue;
		if(vertex == i){
			count++;
			mat[vertex][i] = -2;
			printf("%d* ",i);
			continue;
		}
		if(mat[vertex][i] >= 0){
			mat[vertex][i] = -2;
			mat[i][vertex] = -2;
			count += explore(matrix,i,vertexCount);
			if(mat[i][i]!=-2) printf("%d ",i);
			//printf("%d ",i);
		}
	}
	return count;
}


