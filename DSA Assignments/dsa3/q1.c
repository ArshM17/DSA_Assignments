#include <stdio.h>
#define n 10

int main(){
    int temp;
    int arr[n];
    printf("Enter 10 space seperated integers:\n");
    for(int i = 0; i < n; i++){
        scanf("%d,", &arr[i]);
    }
    printf("Input array is:\n");   
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    for(int i = 0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    printf("\nReversed array is:\n"); 
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
