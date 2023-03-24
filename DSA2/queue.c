#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct queue{
	int *array;
	int front;
	int rear;
	int size;
	int count;
}queue;

void queueInit(queue* q,int size){
	q->size = size;
	q->array = (int*)malloc(sizeof(int)*size);
	q->count = 0;
	q->front = -1;
	q->rear = -1;
}

int isEmpty(queue* q){
	return q->count == 0;
}

int isFull(queue* q){
	return q->count == q->size;
}

int enqueue(queue* q, int val){
	if(isFull(q)){
		printf("%d\n",INT_MAX);
		return INT_MAX;
	}
	if(isEmpty(q)){
		q->front = 0;
	}
	q->rear = (q->rear + 1)%(q->size);
	q->array[q->rear] = val;
	q->count = q->count + 1;
	return 1;
}

int dequeue(queue* q){
	if(isEmpty(q)) {
		printf("%d\n",INT_MAX);
		return INT_MAX;
	}
	printf("%d\n",q->array[q->front]);
	q->front = (q->front + 1)%(q->size);
	q->count = q->count - 1;
	if(isEmpty(q)){
		q->front = -1;
		q->rear = -1;
	}
	return 1;
}	
	
void displayQueue(queue* q){
	int front = q->front;
	int* arr = q->array;
	int count = q->count;
	int size = q->size;
	while(count>0){
		printf("%d\n",arr[front]);
		front = (front+1)%size;
		count--;
	}
}

int main(){
//	queue q;
//	queueInit(&q,1);
//	enqueue(&q,10);
//	enqueue(&q,20);
//	enqueue(&q,30);
//	enqueue(&q,40);
//	enqueue(&q,50);
//	enqueue(&q,60);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	enqueue(&q,200);
//	enqueue(&q,300);
//	enqueue(&q,400);
//	enqueue(&q,500);
//	enqueue(&q,600);
//	enqueue(&q,700);
//	enqueue(&q,800);
//	enqueue(&q,900);
//	enqueue(&q,1000);
//	enqueue(&q,1100);
//	enqueue(&q,1200);
//	enqueue(&q,1300);
//	enqueue(&q,1400);
//	enqueue(&q,1500);
//	enqueue(&q,1600);
//	enqueue(&q,1700);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	displayQueue(&q);
	return 0;
}
