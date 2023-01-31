#include<stdio.h>
#include<stdlib.h>

struct member{
	int pnr;
	char* name;
	struct member* next;
};

void addMember(struct member* a,int num, char name[]){
	while(a->next != NULL){
		a=a->next;
	}
	a->next = malloc(sizeof(struct member));
	a->next->pnr = num;
	a->next->name = name;
	a->next->next = NULL;
}

void displayMembers(struct member* a){
	while(a != NULL){
		printf("%d-%s\n",a->pnr,a->name);
		a=a->next;
	}
}

int countMembers(struct member* a){
	int count = 0;	
	while(a!=NULL){
		count++;
		a=a->next;
	}
	return count;
}

void removeMember(struct member** a,int pnr){
	if((*a)->pnr == pnr){
		struct member* temp = *a;
		*a = (*a)->next;
		free(temp);
		return;
	}
	struct member* curr = *a;
	while(curr->next!=NULL){
		if(curr->next->pnr == pnr){
			struct member *temp = curr->next;
			curr->next=curr->next->next;
			free(temp);
			break;
		}
		curr=curr->next;
	}
}	


int main(){
	struct member* head = malloc(sizeof(struct member));
	addMember(head,10,"abc");
	addMember(head,20,"bcd");
	addMember(head,30,"cde");
	addMember(head,40,"def");
	addMember(head,50,"efg");
	addMember(head,60,"ghi");
	addMember(head,70,"hij");
	addMember(head,80,"ijk");
	printf("Before:\n");
	displayMembers(head);
	removeMember(&head,40);
	printf("After:\n");
	displayMembers(head);
	struct member test;
	printf("%d",test.pnr);
	return 0;
}
