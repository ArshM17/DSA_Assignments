#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

typedef struct linkedList{
	node* head;
	int size;
}linkedList;

linkedList* newLinkedList(){
	linkedList* new = malloc(sizeof(linkedList));
	new->head = NULL;
	new->size = 0;
	return new;
}

//typedef node* list;

void printList(linkedList* list){
	node* temp = list->head;
	while(temp){
		printf("%d->",temp->val);
		temp = temp->next;
	}
	printf("NULL\n");
}

void appendNode(linkedList* list, int val){
	node* head = list->head;
	if(!head){
		head = malloc(sizeof(node));
		head->val = val;
		head->next = NULL;
		list->head = head;
		return;
	}
	while(head->next){
		head = head->next;
	}
	head->next = malloc(sizeof(node));
	head->next->next = NULL;
	head->next->val = val;
}
/*
void appendNodeAt(list *head,int val,int position){
	if(!*head){
		appendNode(head,val);
		return;
	}
	if(position==0){
		node* temp = malloc(sizeof(node));
		temp->val = val;
		temp->next = *head;
		*head = temp;
		return;
	}
	node* curr = *head;
	while(curr->next && position!=1){
		curr = curr->next;
		position--;
	}
	node *temp = malloc(sizeof(node));
	temp->next = curr->next;
	curr->next = temp;
	temp->val = val;
}

void deleteNodeAt(list *head,int position){
	if(position==0){
		node* temp = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}
	node* temp = *head;
	while(position!=1){
		if(!(temp->next)){
			return;
		}
		temp = temp->next;
		position--;
	}
	node* temp2 = temp->next;
	temp->next = temp->next->next;
	free(temp2);
}

void reverse(list* head){
	if(*head == NULL || (*head)->next == NULL) return;
	node* first = *head;
	node* second = (*head)->next;
	node* third = (*head)->next->next;
	while(third){
		second->next = first;
		first = second;
		second = third;
		third = third->next;
	}
	second->next = first;
	(*head)->next = NULL;
	*head = second;
}*/

int main(){
	linkedList* list = newLinkedList();
	appendNode(list,10);
	appendNode(list,20);
	appendNode(list,30);
	appendNode(list,40);
	appendNode(list,50);
	appendNode(list,60);
	printList(list);
}



