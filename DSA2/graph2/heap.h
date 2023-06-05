#ifndef MINHEAP_H
#define MINHEAP_H

#include"adjacencyList.h"

typedef struct {
    	node** heapArr;
    	int capacity;
    	int heapSize;
}minHeap;

minHeap* createMinHeap();

void swapNodes(node** a, node** b);

void heapify(minHeap* heap, int index);

void insertNode(minHeap* heap, node* newNode);

node* extractMin(minHeap* heap);

int isHeapEmpty(minHeap* heap);

#endif /* MINHEAP_H */

