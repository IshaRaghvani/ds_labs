#include <stdio.h>
#include <stdlib.h>
void Selection(int arr[],int n){
    int i,j,small;
    for(i=0;i<n;i++){
        small=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[small]){
                int temp=arr[small];
                arr[small]=arr[j];
                arr[j]=temp;
            }
        }
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
    Selection(arr,n);
    printf("\nSorted array: \n ");

    Print(arr,n);
}