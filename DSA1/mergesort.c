#include<stdio.h>

void merge(int arr[],int l, int m, int r){
	int size1 = m-l+1;
	int size2 = r-m;
	int arrL[size1];
	int arrR[size2];
	
	for(int i = 0;i<size1;i++){
		arrL[i] = arr[l+i];
	}
	
	for(int i = 0;i<size2;i++){
		arrR[i] = arr[m+1+i];
	}
	
	int i = 0;
	int j = 0;
	int k = l;
	
	while(i<size1 && j<size2){
		if(arrR[j]>=arrL[i]){
			arr[k] = arrL[i];
			i++;
		}else{
			arr[k] = arrR[j];
			j++;
		}
		k++;
	}
	
	while(i<size1){
		arr[k]=arrL[i];
		k++;
		i++;
	}
	
	while(j<size2){
		arr[k]=arrR[j];
		k++;
		j++;
	}
	

}

void mergeSort(int arr[], int l, int r){
	if(l<r){
		int m = l + (r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {6, 5, 12, 13, 1, 2,26};
  int size = sizeof(arr) / sizeof(arr[0]);
 // merge(arr,0,3,6);
 // printArray(arr,size);
  mergeSort(arr, 0, size - 1);

 printf("Sorted array: \n");
  printArray(arr, size);
}


