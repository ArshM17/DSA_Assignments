#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
}node;

int linearSearch(int arr[], int start, int target){
	int i = 0;
	while(arr[i] != target) i++;
	return i;
}

node* newNode(int val){
	node* new = malloc(sizeof(node));
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}

node* construct(int instart, int inend, int postend, int inorder[], int postorder[]);

node* constructTree(int inorder[], int postorder[], int size){
	return construct(0, size-1, size-1, inorder, postorder);
}


node* construct(int instart, int inend, int postend, int inorder[], int postorder[]){
	if(instart > inend) return NULL;
	node* root = newNode(postorder[postend]);
	int rootIndex = linearSearch(inorder, instart, root->val);
	root->left = construct(instart, rootIndex-1, postend-(inend-rootIndex)-1, inorder, postorder);
	root->right = construct(rootIndex+1, inend, postend-1, inorder, postorder);
	return root;
}

void inorderTraversal(node* root){
	if(root == NULL) return;
	inorderTraversal(root->left);
	printf("%d ", root->val);
	inorderTraversal(root->right);
}

void postorderTraversal(node* root){
	if(root == NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->val);
}

void preorderTraversal(node* root){
	if(root == NULL) return;
	printf("%d ", root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

int main(){
	int inorder[] = {5,1,99,9,0,89,3,15,20,100,7};
	int postorder[] = {5,99,1,89,0,9,15,100,7,20,3};
//	int inorder[] = {9,3,15,20,7};
//	int postorder[] = {9,15,7,20,3};
//	int inorder[] = {1,2,4,3,5};
//	int postorder[] = {1,4,5,3,2};
	int size = sizeof(postorder)/sizeof(postorder[0]);
	node* root = constructTree(inorder, postorder, size);
	inorderTraversal(root);
	printf("\n");
	postorderTraversal(root);
	return 0;
} 
