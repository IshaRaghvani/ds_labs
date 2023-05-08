#include <stdio.h>
#include <stdlib.h>

void Insertion(int arr[],int n){

    for(int i=1;i<n;i++){
        int current= arr[i];
        int j=i-1;
        // check if current element is smaller than prev
        // then shift that element to left and decrement j
        while(arr[j]>=current &&j>=0 ){ 
            arr[j+1]=arr[j];
            j--;

        }
        //as j is decremented place current element one place after j
        arr[j+1]=current;

    }
 
}

void Print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        
    }
    
}
int main(){
    int n=7;
    int arr[7]={3,20,16,7,1,15,2};
    printf("Unsorted array: \n ");
    Print(arr,n);
    Insertion(arr,n);
    printf("\nSorted array: \n ");

    Print(arr,n);
}