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
		return INT_MAX;
	}
	int temp = q->array[q->front];
	q->front = (q->front + 1)%(q->size);
	q->count = q->count - 1;
	return temp;
}

typedef queue stack;

int push(stack *s, int val){
	enqueue(s,val);
}

int pop(stack *s){
	queue q;
	queueInit(&q,s->size);
	while(s->count > 1){
		enqueue(&q,dequeue(s));
	}
	int temp = dequeue(s);
	*s = q;
	return temp;
}

int main(){
	stack s;
	queueInit(&s,5);
	push(&s,10);
	push(&s,20);
	push(&s,30);
	push(&s,40);
	push(&s,50);
	push(&s,60);
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
//	printf("%d\n",pop(&s));
//	printf("%d\n",pop(&s));
//	printf("%d\n",pop(&s));
}
