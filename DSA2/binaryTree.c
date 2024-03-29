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

int replacement(node* root){
	if(root->right != NULL){
		root = root->right;
		while(root->left != NULL){
			root = root->left;
		}
	}else{
		root = root->left;
		while(root->right != NULL){
			root = root->right;
		}
	}
	return root->data;
}

node* rem(node* root, int val);

void removeNode(bst* tree, int val){
	if(tree == NULL || tree->root == NULL) return;
	node* tempRoot = rem(tree->root, val);
	tree->root = tempRoot;	
}

node* rem(node* root, int val){
	if(root->data == val){
		if(root->left == NULL){
			node* temp = root;
			root = root->right;
			free(temp);
			return root;
		}
		
		if(root->right == NULL){
			node* temp = root;
			root = root->left;
			free(temp);
			return root;
		}		
		int temp = replacement(root);
		root = rem(root, temp);
		root->data = temp;	
	}else if(root->data < val){
		root->right = rem(root->right, val);
	}else{
		root->left = rem(root->left,val);
	}
	return root;
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

void descendantsOf(bst* tree, int val){
	node* root = tree->root;
	node* requiredNode = search(root, val)->root;
	display(requiredNode);
}

void destroy(node* root){
	if(root == NULL) return;
	destroy(root->left);
	node* temp = root->right;
	free(root);
	destroy(temp);
}

void destroyTree(bst* tree){
	node* root = tree->root;
	destroy(root);
	tree->root = NULL;
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
	displayTree(myBST);
//	removeNode(myBST, 2);
	destroyTree(myBST);
	printf("\n");
	displayTree(myBST);
//	descendantsOf(myBST, 17);
}



