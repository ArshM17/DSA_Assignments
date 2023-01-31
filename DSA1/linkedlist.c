#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

typedef node* list;

void printList(list* head){
	node* temp = *head;
	while(temp){
		printf("%d\n",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void appendNode(list* head,int val){
	if(!*head){
		*head = malloc(sizeof(node));
		(*head)->val = val;
		(*head)->next = NULL;
		return;
	}
	node* temp = *head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = malloc(sizeof(node));
	temp->next->next = NULL;
	temp->next->val = val;
}

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
}

int main(){
	list head = NULL;
	appendNode(&head,10);
	appendNode(&head,20);
	appendNode(&head,30);
	appendNode(&head,40);
	appendNode(&head,50);
	appendNode(&head,60);
	appendNodeAt(&head,1234,105555);
	printList(&head);
	
	list head2 = NULL;
	appendNodeAt(&head2,234,1234);
	reverse(&head2);
	printList(&head2);
}
