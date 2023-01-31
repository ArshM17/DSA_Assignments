#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

typedef struct Queue{
	Node* front;
	Node* rear;
}Queue;

Queue* createQueue(){
	Queue* q = malloc(sizeof(Queue));
	q->front = malloc(sizeof(Node));
	q->rear = q->front;
	return q;
}

bool isEmpty(Queue* q){
	if(q->front==q->rear){
		return true;
	}else{
		return false;
	}
}

void enqueue(Queue* q, int val){
	q->rear->data = val;
	q->rear->next = malloc(sizeof(Node));
	q->rear = q->rear->next;
}

void dequeue(Queue* q){
	if(isEmpty(q)){
		printf("Queue is Empty\n");
		return;
	}
	Node* temp = q->front;
	q->front = q->front->next;
	free(temp);
}

void showQueue(Queue *q){
	if(isEmpty(q)){
		printf("Queue is Empty\n");
		return;
	}
	printf("Elements in the queue are: ");
	while(q->front!=q->rear){
		printf("%d ",q->front->data);
		q->front = q->front->next;
	}
	printf("\n");
}

void main(){
	Queue* queue1 = createQueue();
	enqueue(queue1, 10);
	enqueue(queue1, 20);
	enqueue(queue1, 30);
	enqueue(queue1, 40);
	enqueue(queue1, 50);
	enqueue(queue1, 60);
	enqueue(queue1, 70);
	dequeue(queue1);
	dequeue(queue1);
	showQueue(queue1);
}






