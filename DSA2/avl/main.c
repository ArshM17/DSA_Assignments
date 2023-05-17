#include "avl.h"
#include<stdio.h>

int main(){
	tree root;
	init(&root);
	insert(&root, 10);
	insert(&root, 2);
	insert(&root, 31);
	insert(&root, -3);
	insert(&root, 0);
	insert(&root, 13);
	insert(&root, 123);
	insert(&root, -63);
	insert(&root, 12);
	insert(&root, 133);
	insert(&root, 55);
	insert(&root, -100);
	inorder(root);
	printf("\n");
	rem(&root, 55);
	inorder(root);
}
