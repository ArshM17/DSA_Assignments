#include<stdio.h>


int factorial(int n){
	if(n==0 || n==1) return 1;
	return n*factorial(n-1);
}

int countTrees(int n){
	return factorial(2*n)/(factorial(n)*factorial(n)*(n+1));
}

int main(){
	printf("%d ", countTrees(2));
	printf("%d ", countTrees(3));
	printf("%d ", countTrees(4));
	printf("%d ", countTrees(5));
}
