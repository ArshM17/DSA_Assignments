#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct bst{
	node* root;
}bst;

bst* initBST(int val){
	bst* tree = (bst*)malloc(sizeof(bst));
	tree->root = (node*)malloc(sizeof(node));
	tree->root->left = NULL;
	tree->root->right = NULL;
	tree->root->data = val;
	return tree;
}

void add(node* root,int val);

void addNode(bst* tree, int val){
	add(tree->root,val);
}

void add(node* root, int val){
	if(val > root->data){
		if(root->right==NULL){
			root->right = (node*)malloc(sizeof(node));
			root->right->data = val;
			return;
		}
		add(root->right,val);
	}else{
		if(root->left==NULL){
			root->left = (node*)malloc(sizeof(node));
			root->left->data = val;
			return;
		}
		add(root->left,val);
	}
}

void display(node* root);

void displayTree(bst* tree){
	display(tree->root);
}

void display(node* root){
	if(root==NULL) return;
	printf("%d ",root->data);
	display(root->left);
	display(root->right);
}


int main(){
	bst* myBST = initBST(1);
	addNode(myBST,3);
	addNode(myBST,7);
	addNode(myBST,17);
	addNode(myBST,11);
	addNode(myBST,15);
	addNode(myBST,13);
	addNode(myBST,19);
	addNode(myBST,21);
	addNode(myBST,2);
	displayTree(myBST);
}



