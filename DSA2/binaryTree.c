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

bst* initBST(){
	bst* tree = (bst*)malloc(sizeof(bst));
	tree->root = NULL;
	return tree;
}

void add(node* root,int val);

void addNode(bst* tree, int val){
	if(tree->root == NULL){
		tree->root = (node*)malloc(sizeof(node));
		tree->root->left = NULL;
		tree->root->right = NULL;
		tree->root->data = val;
	}else{
		add(tree->root,val);
	}
}

void add(node* root, int val){
	if(val > root->data){
		if(root->right == NULL){
			root->right = (node*)malloc(sizeof(node));
			root->right->data = val;
			return;
		}
		add(root->right,val);
	}else{
		if(root->left == NULL){
			root->left = (node*)malloc(sizeof(node));
			root->left->data = val;
			return;
		}
		add(root->left, val);
	}
}

bst* search(node* root, int val);

bst* searchNode(bst* tree, int val){
	if(tree->root == NULL) return NULL;
	return search(tree->root, val);
}

bst* search(node* root, int val){
	if(root->data == val){
		bst* temp = initBST();
		temp->root = root;
		return temp;
	}
	if(root->left == NULL && root->right == NULL){
		printf("Not found");
		return NULL;
	}
	if(root->data < val){
		search(root->right, val);
	}else if(root->data > val){
		search(root->left, val);
	}
}

void removeNode(bst* tree, int val){
	if(tree->root == NULL) return;
	if(search(tree, val) == NULL) return;
	remove(tree->root, val);
}

void remove(node* root, int val){
	if(root->data == val){
		
	}else if(root->data < val){
		remove(root->right, val);
	} 
	
}

void display(node* root);

void displayTree(bst* tree){
	if(tree == NULL) return;
	display(tree->root);
}

void display(node* root){
	if(root==NULL) return;
	display(root->left);
	printf("%d ",root->data);
	display(root->right);
}


int main(){
	bst* myBST = initBST();
	addNode(myBST,3);
	addNode(myBST,7);
	addNode(myBST,17);
	addNode(myBST,11);
	addNode(myBST,15);
	addNode(myBST,13);
	addNode(myBST,19);
	addNode(myBST,21);
	addNode(myBST,2);
//	bst* temp = searchNode(myBST, 15);
//	displayTree(myBST);
//	displayTree(temp);
}



