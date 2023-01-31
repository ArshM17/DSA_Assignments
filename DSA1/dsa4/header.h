int linearSearch(int arr[], int n, int x){
	for(int j = 0;j<n;j++){
		if(arr[j]==x){
			printf("Target %d found at index %d\n",x,j);
			return 0;
		}
	}
	printf("Target not found\n");
	return 0;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int insertionSort(int arr[], int n);

int binarySearch(int arr[], int n, int x){
	insertionSort(arr,n);
	int high=0,low=n-1,mid;
	while(high>low){
		mid=(high+low)/2;
		if(arr[mid]==x){
			printf("Target %d found at %d\n",x,mid);
			return 0;
		}
		if(arr[mid]<x){
			low = mid+1;	
		}else{
			high = mid-1;
		}
	}
	printf("Target %d not found\n",x);
	return 0;
}

int bubbleSort(int arr[], int n){
	for(int j = 0;j<n;j++){
		for(int k = 1;k<n;k++){
			if(arr[k-1]>arr[k]){
				swap(&arr[k-1],&arr[k]);
			}
		}
	}
}

int insertionSort(int arr[], int n){
	for(int j = 1;j<n;j++){
		while(arr[j]<arr[j-1] && j>0){
			swap(&arr[j],&arr[j-1]);
			j--;
		}
	}
}

int selectionSort(int arr[], int n){
	int min,index;
	for(int j = 0;j<n;j++){
		min  = j;
		for(int k = j;k<n;k++){
			if(arr[k]<arr[min]) min=k;
		}
		if(min!=j) swap(&arr[min],&arr[j]);
	}
}
