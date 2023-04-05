#include<stdio.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef node* BST;

levelOrderTraversal(BST root){
	Queue q;
	init(&q);
	queue(&q,root);
	while(!isEmpty(&q)){
		int size = size(&q);
		for(int i = 0 ; i < size ; i++){
			node* curr = dequeue(&q);
			printf("%d ", curr->data);
			if(curr->left != NULL) queue(&q, curr->left);
			if(curr->right != NULL) queue(&q, curr->right);
		}
	}
}

int main(){
	levelOrderTraversal(BST tree);
}

