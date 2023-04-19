#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char val;
	struct node* left;
	struct node* right;
}node;

void countFrequencyOfLeafNodes(int freq[], node* root, int step);

int main(){
	
	node* root1 = malloc(sizeof(node));
	root1->val = '+';
	root1->left = malloc(sizeof(node));
	root1->right = malloc(sizeof(node));

	root1->left->val = 'a';
	root1->left->left = NULL;
	root1->left->right = NULL;

	root1->right->val = '+';

	root1->right->left = malloc(sizeof(node));
	root1->right->right = malloc(sizeof(node));

	root1->right->left->val = 'e';
	root1->right->right->val = 'd';

	node* root2 = malloc(sizeof(node));
	root2->val = '+';
	root2->left = malloc(sizeof(node));
	root2->right = malloc(sizeof(node));

	root2->right->val = 'a';
	root2->right->left = NULL;
	root2->right->right = NULL;

	root2->left->val = '+';

	root2->left->left = malloc(sizeof(node));
	root2->left->right = malloc(sizeof(node));

	root2->left->left->val = 'd';
	root2->left->right->val = 'e';
	int freq[150];

	for(int i = 0; i<150;i++){
		freq[i] = 0;
	}

	countFrequencyOfLeafNodes(freq, root1, 1);
//	for(int i = 0; i<150;i++){
//		printf("%d ", freq[i]);
//	}
//	printf("\n");
	countFrequencyOfLeafNodes(freq, root2, -1);
//	for(int i = 0; i<150;i++){
//		printf("%d ", freq[i]);
//	}
	int flag = 0;
	for(int i = 0; i<150;i++){
		if(freq[i] != 0){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		printf("The trees are not equivalent");
	}else{
		printf("The trees are equivalent");
	}
	return 0;
}

void countFrequencyOfLeafNodes(int freq[], node* root, int step){
	if(root == NULL){
		return;	
	}
	if(root->left == NULL && root->right == NULL){
		freq[root->val]+=step;
		return;
	}
	countFrequencyOfLeafNodes(freq, root->left, step);
	countFrequencyOfLeafNodes(freq, root->right, step);
}



