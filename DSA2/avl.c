#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	int balanceFactor;
}node;

typedef struct bst{
	node* root;
}bst;

bst* initBST(){
	bst* tree = (bst*)malloc(sizeof(bst));
	tree->root = NULL;
	return tree;
}

int heightOf(node* root){
	if(root == NULL) return 0;
	int left = heightOf(root->left);
	int right = heightOf(root->right);
	return 1 + (left > right ? left : right);
}

void add(node** n, int val);

void addNode(bst* tree, int val){
	if(tree->root == NULL){
		tree->root = (node*)malloc(sizeof(node));
		tree->root->left = NULL;
		tree->root->right = NULL;
		tree->root->data = val;
		tree->root->balanceFactor = 0;
		return;
	}
	add(&(tree->root),val);
}

void add(node** n, int val){
	node* root = *n;
	if(val == root->data) return;
	if(val > root->data){
		if(root->right == NULL){
			root->right = (node*)malloc(sizeof(node));
			root->right->data = val;
			root->balanceFactor = heightOf(root->left) - heightOf(root->right);
			return;
		}
		add(&(root->right),val);
		root->balanceFactor = heightOf(root->left) - heightOf(root->right);
		if(root->balanceFactor == -2){
			if(root->right->data > val){
				//RL rotation;
				node* temp = root->right;
				node* temp2 = root->right->left->right;
				root->right = root->right->left;
				temp->left = temp2;
				root->right = temp;
				
				temp = root;
				*n = temp->right;
				temp2 = temp->right->left;
				temp->right = temp2;
				(*n)->left = temp;
			}else{
				//RR rotation;
				node* temp = root;
				*n = temp->right;
				node* temp2 = temp->right->left;
				temp->right = temp2;
				(*n)->left = temp;
			}
		}
	}else{
		if(root->left == NULL){
			root->left = (node*)malloc(sizeof(node));
			root->left->data = val;
			root->balanceFactor = heightOf(root->left) - heightOf(root->right);
			return;
		}
		add(&(root->left), val);
		root->balanceFactor = heightOf(root->left) - heightOf(root->right);
		if(root->balanceFactor == 2){
			if(root->left->data < val){
				//LR rotation;
				node* temp = root->left;
				node* temp2 = root->left->right->left;
				root->right = root->left->right;
				temp->right = temp2;
				root->left = temp;
				
				temp = root;
				*n = temp->left;
				temp2 = temp->left->right;
				temp->left = temp2;
				(*n)->right = temp;

			}else{
				//LL rotation;
				node* temp = root;
				*n = temp->left;
				node* temp2 = temp->left->right;
				temp->left = temp2;
				(*n)->right = temp;
			}
		}
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

void display(node* root);
void display2(node* root);

void displayTree(bst* tree){
	if(tree == NULL) return;
	display(tree->root);
}

void display(node* root){
	if(root==NULL) return;
	display(root->left);
	printf("%d %d",root->data, root->balanceFactor);
	display(root->right);
}

void displayTree2(bst* tree){
	if(tree == NULL) return;
	display2(tree->root);
}

void display2(node* root){
	if(root==NULL) return;
//	printf("%d %d",root->data, root);
	display2(root->left);
	display2(root->right);
}


int main(){
	bst* tree = initBST();
	addNode(tree, 1);
	addNode(tree, 2);
	addNode(tree, 4);
	addNode(tree, 12);
	addNode(tree, 17);
	addNode(tree, 56);
	addNode(tree, 70);
	addNode(tree, 80);
	displayTree(tree);
	printf("\n");
//	displayTree2(tree);
}

