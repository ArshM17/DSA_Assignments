#ifndef STACK_H
#define STACK_H

typedef struct stack{
	int *array;
        int top;
        int size;
}stack;

void stackInit(stack* s,int size);

int isEmpty(stack* s);

int isFull(stack* s);

int peek(stack* s);

void push(stack* s, int val);

int pop(stack* s);

void displayStack(stack* s);

#endif
