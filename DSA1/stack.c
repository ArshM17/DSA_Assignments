#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct stack{
	int *array;
	int top;
	int size;
}stack;

void stackInit(stack* s,int size){
	s->size = size;
	s->array = (int*)malloc(sizeof(int)*size);
	s->top = -1;
}

int isEmpty(stack* s){
	if(s->top==-1) return 1;
	return 0;
//	return (s->top==-1?1:0);
}

int isFull(stack* s){
	if(s->top == (s->size)-1) return 1;
	return 0;
}

int peek(stack* s){
	if(isEmpty(s)){
		return INT_MAX;
	}
	return s->array[s->top];
}

int push(stack* s, int val){
	if(isFull(s)){
		printf("%d\n",INT_MAX);
		return INT_MAX;
	}
	s->top =  s->top + 1;
	s->array[s->top] = val;
}

int pop(stack* s){
	if(isEmpty(s)) {
		printf("%d\n",INT_MAX);
		return INT_MAX;
	}
	s->top = (s->top) - 1;
	return s->array[s->top];
}

void displayStack(stack* s){
	int top = s->top;
	int* arr = s->array;
	while(top>=0){
		printf("%d\n",arr[top]);
		top--;
	}
}

int main(){
	stack s;
	stackInit(&s,10);
	push(&s,10);
	push(&s,20);
	push(&s,30);
	push(&s,40);
	pop(&s);
	pop(&s);
	pop(&s);
	displayStack(&s);
	pop(&s);
	pop(&s);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	push(&s,40);
	displayStack(&s);
	return 0;
}
