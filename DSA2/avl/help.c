#include<stdlib.h>
#include<stdio.h>
#include "avl.h"

void init(tree* root){
	*root = NULL;
	return;
}

int max(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int heightOf(node* n){
	if(n == NULL){
		return 0;
	}
	return 1 + max(heightOf(n->left),heightOf(n->right));
}

node* findImbalancedAncestor(node* curr){
	while(curr){
		curr->bf = heightOf(curr->left) - heightOf(curr->right);
		if(curr->bf == 2 || curr->bf == -2){
			return curr;
		}
		curr = curr->parent;	
	}
	return NULL;
}

void lRotation(tree* root, node* a){
	node* parent = a->parent;
	node* b = a->left;
	node* bRight = b->right;
	b->right = a;
	a->parent = b;
	a->left = bRight;
	if(bRight){
		bRight->parent = a;
	}
	b->parent = parent;
	if(!parent){
		*root = b;
	}else{
		if(parent->left == a){
			parent->left = b;
		}else{
			parent->right = b;
		}
	}
	return;
}

void rRotation(tree* root, node* a){
	node* parent = a->parent;
	node* b = a->right;
	node* bLeft = b->left;
	b->left = a;
	a->parent = b;
	a->right = bLeft;
	if(bLeft){
		bLeft->parent = a;
	}
	b->parent = parent;
	if(!parent){
		*root = b;
	}else{
		if(parent->left == a){
			parent->left = b;
		}else{
			parent->right = b;
		}
	}
	return;
}

void lrRotation(tree* root, node* a){
	rRotation(root, a->left);
	lRotation(root, a);
}

void rlRotation(tree* root, node* a){
	lRotation(root, a->right);
	rRotation(root, a);
}

void adjustImbalancedNode(tree* root, node* curr, int val){
	if(val > curr->val){
		if(val > curr->right->val){
			rRotation(root, curr);
		}else{
			rlRotation(root, curr);
			curr->parent->right->bf = heightOf(curr->parent->right->left)-heightOf(curr->parent->right->right);
		}
	}else{
		if(val < curr->left->val){
			lRotation(root, curr);
		}else{
			lrRotation(root, curr);
			curr->parent->left->bf = heightOf(curr->parent->left->left)-heightOf(curr->parent->left->right);
		}
	}
	curr->bf = heightOf(curr->left)-heightOf(curr->right);
	curr->parent->bf = heightOf(curr->parent->left)-heightOf(curr->parent->right);
}

void insert(tree* root, int val){
	node* newNode = malloc(sizeof(node));
	newNode->val = val;
	newNode->bf = 0;
	newNode->parent = newNode->left = newNode->right = NULL;
	
	if(!*root){
		*root = newNode;
		return;
	}
	
	node *temp = *root, *parent = NULL;
	while(temp){
		parent = temp;
		if(temp->val == val){
			free(newNode);
			return;
		}else if(val > temp->val){
			temp = temp->right;
		}else{
			temp = temp->left;
		}
	}
	
	if(val > parent->val){
		parent->right = newNode;
	}else{
		parent->left = newNode;
	}
	newNode->parent = parent;
	
	node* imbalancedNode = findImbalancedAncestor(newNode);
	
	if(imbalancedNode == NULL) return;
	
	adjustImbalancedNode(root, imbalancedNode, val);
	
}

node* findNode(node* root, int val){
	while(root){
		if(root->val == val){
			return root;
		}else if(val < root->val){
			root = root->left;
		}else{
			root = root->right;
		}
	}
	return NULL;
}

void rem(tree* root, int val){
	node* pr;
	if(*root == NULL) return;
	node* nodeToBeRemoved = findNode(*root, val);
	if(!nodeToBeRemoved) return;
	node* parent = nodeToBeRemoved->parent;
	
	if(nodeToBeRemoved->left == NULL && nodeToBeRemoved->right == NULL){
		if(parent == NULL) {
			*root == NULL;
		}else{
			if(parent->left == nodeToBeRemoved){
				parent->left = NULL;
			}else{
				parent->right = NULL;
			}
		}
		free(nodeToBeRemoved);
	}else if(nodeToBeRemoved->right == NULL){
		if(parent == NULL){
			*root = nodeToBeRemoved->left;
		//	free(nodeToBeRemoved);
		}else{
			if(parent->left == nodeToBeRemoved){
				parent->left = nodeToBeRemoved->left;		
			}else{
				parent->right = nodeToBeRemoved->left;
			}
		}
		if(nodeToBeRemoved->left != NULL){
			nodeToBeRemoved->left->parent = parent;
		}
		free(nodeToBeRemoved);
	}else{
		if(nodeToBeRemoved->right->left == NULL){
			if(parent == NULL){
				*root = nodeToBeRemoved->right;
			}else{		
				if(parent->left == nodeToBeRemoved){
					parent->left = nodeToBeRemoved->right;		
				}else{
					parent->right = nodeToBeRemoved->right;
				}
			}
			node* remLeft = nodeToBeRemoved->left;
			nodeToBeRemoved->right->left = remLeft;
			if(remLeft != NULL){
				remLeft->parent = nodeToBeRemoved->right;
			}
			free(nodeToBeRemoved);
		}else{
			node* temp = nodeToBeRemoved->right->left;
			while(temp->left){
				temp = temp->left;
			}
			nodeToBeRemoved->val = temp->val;
			temp->val = val;
			temp->parent->left = temp->right;
			if(temp->right!=NULL){
				temp->right->parent = temp->parent;
			}
			free(nodeToBeRemoved);
		}
		
	}
	return;
}

void inorder(tree root){
	if(!root){
		return;
	}
	inorder(root->left);
	if(root->parent){
		printf("Val: %d, Parent:%d, Bf: %d\n", root->val,root->parent->val,root->bf);
	}else{
		printf("Val: %d, Parent:NULL, Bf: %d\n", root->val,root->bf);	
	}
	inorder(root->right);
}



