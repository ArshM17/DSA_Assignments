#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}node;

typedef struct doublyLinkedList{
	int size;
	node* start;
	node* end;
}dll;

dll* init(){
	dll* list = malloc(sizeof(dll));
	list->size = 0;
	list->start = NULL;
	list->end = NULL;
	return list;
}

void addAtStart(dll* list,int val){
	node* newNode = malloc(sizeof(node));
	newNode->data = val;
	newNode->prev = NULL;
	if(list->start == NULL && list->end == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		list->start = newNode;
		list->end = newNode;
		list->size++;
		return;
	}
	newNode->next = list->start;
	list->start->prev = newNode;
	list->start = newNode;
	list->size++;
}

void addAtEnd(dll* list,int val){
	node* newNode = malloc(sizeof(node));
	newNode->data = val;
	newNode->next = NULL;
	if(list->start == NULL && list->end == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		list->start = newNode;
		list->end = newNode;
		list->size++;
		return;
	}
	newNode->prev = list->end;
	list->end->next = newNode;
	list->end = newNode;
	list->size++;
}

void addNodeAt(dll* list,int pos,int val){
	node* newNode = malloc(sizeof(node));
	newNode->data = val;
	if(list->start == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		list->start = newNode;
		list->end = newNode;
		list->size++;
		return;
	}
	if(pos==0){
		addAtStart(list,val);
		return;
	}
	if(pos>list->size){
		addAtEnd(list,val);
		return;
	}
	node* temp = list->start;
	while(pos!=0){
		pos--;
		temp = temp->next;
	}
	newNode->prev = temp->prev;
	newNode->next = temp;
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;
	list->size++;
}

void printListFromStart(dll* list){
	node* temp = list->start;
	while(temp){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void removeNodeAt(dll* list, int pos){
	if(list->start==NULL){
		return;
	}
	if(list->size==1){
		list->size==0;
		free(list->start);
		list->start==NULL;
		list->end==NULL;
		return;
	}
	if(pos==0){
		node* temp = list->start;
		list->start->next->prev = NULL;
		list->start = list->start->next;
		free(temp);
		list->size = 0;
		return;
	}
	if(pos==(list->size-1)){
		node* temp = list->end;
		list->end->prev->next = NULL;
		list->end = list->end->prev;
		free(temp);
		list->size = 0;
		return;
	}
	node* temp = list->start;
	while(pos!=0){
		pos--;
		temp = temp->next;
	}
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	free(temp);
	list->size--;
}

int main(){
	dll* list = init();
	addAtStart(list,55);
	addAtStart(list,65);
	addAtStart(list,75);
	addAtStart(list,85);
	addAtStart(list,95);
	addAtEnd(list,3434);
	addAtEnd(list,343);
	addAtEnd(list,34);
	addAtEnd(list,3);
	addNodeAt(list,0,500);
	printListFromStart(list);
	removeNodeAt(list,8);
	printListFromStart(list);
}
