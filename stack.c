#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define size 5

int stack[size];
int top = -1;

typedef struct node{
	int data;
	struct node* next;
}node;

void arrPush(int stack[],int val){
	if(top==size-1){
		printf("Stack is already full");
		return;
	}else{
		top++;
		stack[top]=val;
	}
}

void arrPop(int stack[]){
	if(top==-1){
		printf("Stack is empty");
		return;
	}else{
		printf("%d was popped\n",stack[top]);
		top--;
	}
}

bool isEmpty(int stack[]){
	return top==-1;	
}

bool isFull(int stack[]){
	return top==size-1;
}

void llPush(){
	
}

void llPop(){
	
}

void printStack(int stack[]){
	for(int i = top;i>=0;i--){
		printf("%d ",stack[i]);
	}
}
	
int main(){
	arrPush(stack,10);
	arrPush(stack,20);
	arrPush(stack,30);
	arrPush(stack,40);
	arrPush(stack,50);
	printStack(stack);
	printf("%s",isFull(stack)?"true":"false");
}
