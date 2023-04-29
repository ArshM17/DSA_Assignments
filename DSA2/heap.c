#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct heap{
	int* arr;
	int n;
	int curr;
}heap;

heap* initHeap();

void insert(heap* h, int val);

int removeMax(heap* h);

void swim(heap* h, int i);

void sink(heap* h, int i);

void printArr(int* arr, int size);

int main(){
	heap* h = initHeap(10);
	insert(h, 1);
	insert(h, 2);
	insert(h, 3);
	insert(h, 4);
	insert(h, 5);
	insert(h, 6);
	insert(h, 7);
	insert(h, 8);
	insert(h, 9);
	insert(h, 10);
	insert(h, 11);
	printArr(h->arr,h->curr);
	removeMax(h);
	removeMax(h);
	removeMax(h);
	removeMax(h);
	removeMax(h);
	removeMax(h);
	printArr(h->arr,h->curr);
}

heap* initHeap(int n){
	heap* h = malloc(sizeof(heap));
	h->n = n;
	h->curr = 0;
	h->arr = malloc(sizeof(int)*n);
	for(int i = 0;i<n;i++){
		h->arr[i] = INT_MIN;
	}
	return h;
}

void insert(heap* h, int val){
	if(h->curr >= h->n){
		printf("Heap is full, cannot insert %d \n", val);
		return;
	}
	h->arr[h->curr] = val;
	swim(h, h->curr);
	h->curr++;
}

void swim(heap* h, int i){
	while(i>=0){
		if(h->arr[i] > h->arr[(i-1)/2]){
			int temp = h->arr[i];
			h->arr[i] = h->arr[(i-1)/2];
			h->arr[(i-1)/2] = temp;
			i = (i-1)/2;
		}else{
			break;
		}
	}
}

int removeMax(heap* h){
	if(h->curr == 0){
		printf("Heap is empty, nothing to remove");
		return INT_MIN;
	}
	int max = h->arr[0];
	h->arr[0] = h->arr[h->curr - 1];
	h->arr[h->curr - 1] = INT_MIN;
	h->curr--;
	sink(h, 0);
	return max;
}

void sink(heap* h, int i){
	while(2*i+1 < h->curr){
		int temp = h->arr[i];
		if(h->arr[2*i+1] < h->arr[i] && h->arr[2*i+2] < h->arr[i]) break;
		if(h->arr[2*i+1] < h->arr[2*i+2]){
			h->arr[i] = h->arr[2*i+2];
			h->arr[2*i+2] = temp;
			i = 2*i+2;
		}else{
			h->arr[i] = h->arr[2*i+1];
			h->arr[2*i+1] = temp;
			i = 2*i+1;
		}
	}
}

void printArr(int* arr, int size){
	for(int i = 0;i<size;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


