#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define SIZE 100

typedef struct stack{
	char *arr;
	int top,size;
}stack;

void printString(char string[]){
	for(int i = 0;string[i]!='\0';i++){
		printf("%c",string[i]);
	}
	printf("\n");
}

stack* createStack(int size){
	stack* s = malloc(sizeof(stack));
	s->size = size;
	s->arr = malloc(sizeof(char)*size);
	s->top = -1;
	return s;
}

void push(stack *s, char val){
	s->arr[++s->top]=val;
}

char pop(stack *s){
	char temp = s->arr[s->top--];
	return temp;
}

void printReverse(char string[]){
	stack *s = createStack(SIZE);
	s->top = -1;
	for(int i = 0;string[i]!='\0';i++){
		push(s,string[i]);
	}
//	printStack(s);
//	printf("%d",s->top);
	int temp = s->top;
	char rev[SIZE+1];
	int i = 0;
	while(temp >= 0){
		rev[i]=pop(s);
		temp--;
		i++;
	}
	rev[i] = '\0';
	printf("%s",rev);
}

void printStack(stack *s){
	int temp = s->top;
	while(temp>=0){
		printf("%c ",s->arr[temp--]);
	}
}

bool isPallindrome(char string[]){
	int size = 0;
	while(string[size]!='\0'){
		size++;
	}
	for(int i = 0;i<size/2;i++){
		if(string[i]!=string[size-i-1]){
			return false;
		}
	}
	return true;
	printf(" %c ",string[0]);
	printf(" %c ",string[size-1]);
}	

int main(){
	char string[100];
	printf("Enter a string:\n");
	scanf("%s",string);
	printf("Input string is: ");
	printString(string);
	printf("Reversed string is: ");
	printReverse(string);
//	isPallindrome(string);
	printf("\n");
	if(isPallindrome(string)){
		printf("Input string is a pallindrome");
	}else{
		printf("Input string is not a pallindrome");
	}
	printf("\n");
}
