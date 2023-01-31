#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int main(){
	int n;
	printf("Enter array size:\n");
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i<n;i++){
		arr[i]=rand()%50;
	}
	printf("Unsorted array is:\n");
	for(int i = 0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nWhat do you want to do with the array?\n1)Search 2)Sort\n");
	int i;
	scanf("%d",&i);
	if(i==1){
		printf("How do you want to search?\n1)Linear Search 2)Binary Search\n");
		int j;
		scanf("%d",&j);
		printf("Enter target element:\n");
		int target;
		scanf("%d",&target);
		if(j==1){
			linearSearch(arr,n,target);
		}else{
			binarySearch(arr,n,target);
		}
	}else{
		printf("How do you want to sort?\n1)Bubble Sort 2)Selection Sort 3)Insertion Sort\n");
		int j;
		scanf("%d",&j);
		if(j==1){
			bubbleSort(arr,n);
		}else if(j==2){
			selectionSort(arr,n);
		}else{
			insertionSort(arr,n);
		}
		printf("Sorted array is:\n");
		for(int i = 0;i<n;i++){
			printf("%d ",arr[i]);
		}
	}
	return 0;
}
