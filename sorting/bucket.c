#include <stdio.h>
#include <stdlib.h>
int getMax(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        return max;
    }

}
void Bucket(int arr[],int n){
    int max=getMax(arr,n);
    int bucket[max+1],i; //create buckets
    for(int i=0;i<=max;i++){
        bucket[i]=0; //initialize buckets to 0
    }
    for(int i=0;i<n;i++){
        bucket[arr[i]]++; //push elements in corresponnding buckets
    }
    //merge buckets
    for(int i=0,j=0;i<=max;i++){
        //j points at the index we are updating
        while(bucket[i]>0){ //run this till there is an element in bucket
            //update the array and check all elemnets in j
            arr[j++]=i;
            //decerese count of bucket elements
            bucket[i]--;

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
    
    printf("\nSorted array: \n ");
    Bucket(arr,7);

    Print(arr,n);
}