#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define MAXSIZE 100


minHeap* createMinHeap() {
    	minHeap* heap = (minHeap*)malloc(sizeof(minHeap));
    	heap->heapArr = (node**)malloc(MAXSIZE * sizeof(node*));
    	heap->capacity = MAXSIZE;
    	heap->heapSize = 0;
    	return heap;
}

void swapNodes(node** a, node** b) {
	node* temp = *a;
 	*a = *b;
	*b = temp;
}

void heapify(minHeap* heap, int index) {
    	int smallest = index;
    	int left = 2 * index + 1;
    	int right = 2 * index + 2;

    	if (left < heap->heapSize && heap->heapArr[left]->weight < heap->heapArr[smallest]->weight)
        	smallest = left;

    	if (right < heap->heapSize && heap->heapArr[right]->weight < heap->heapArr[smallest]->weight)
        	smallest = right;

    	if (smallest != index) {
        	swapNodes(&heap->heapArr[index], &heap->heapArr[smallest]);
        	heapify(heap, smallest);
    	}
}

void insertNode(minHeap* heap, node* newNode) {
    	if (heap->heapSize == heap->capacity) {
        	printf("Heap is full. Cannot insert more nodes.\n");
        	return;
    	}

    	int i = heap->heapSize;
    	heap->heapSize++;
    	heap->heapArr[i] = newNode;

    	while (i != 0 && heap->heapArr[(i - 1) / 2]->weight > heap->heapArr[i]->weight) {
        	swapNodes(&heap->heapArr[(i - 1) / 2], &heap->heapArr[i]);
        	i = (i - 1) / 2;
   	}
}

node* extractMin(minHeap* heap) {
    	if (heap->heapSize <= 0)
    	    return NULL;

    	if (heap->heapSize == 1) {
    	    heap->heapSize--;
    	    return heap->heapArr[0];
    	}

    	node* minNode = heap->heapArr[0];
    	heap->heapArr[0] = heap->heapArr[heap->heapSize - 1];
    	heap->heapSize--;
    	heapify(heap, 0);

    	return minNode;
}

int isHeapEmpty(minHeap* heap) {
    	return heap->heapSize == 0;
}

