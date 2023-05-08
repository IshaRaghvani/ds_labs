// Bubble sort in C

#include <stdio.h>

void bubbleSort(int array[],int size){
    
    for(int i=0;i<size-1;++i){
        for(int j=0;j<size-i-1;++j){
            
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
void Print(int array[],int size){
    for(int i=0;i<size;++i){
        printf("%d ",array[i]);
        
    }
    printf("\n");
}

int main(){
    int n=6;
    int arr[6]={2,7,12,1,9,5};
    
    printf("Unsorted array: ");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr,n);
    
    printf("Sorted array: ");
    Print(arr,n);
    
}





