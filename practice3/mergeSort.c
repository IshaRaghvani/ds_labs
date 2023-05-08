#include <stdio.h>

void merge(int A[],int low,int mid,int high){
    int B[100];
    int i,j,k;

    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
                B[k]=A[i];
                i++,k++;
        }
        else{
                B[k]=A[j];
                j++,k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        i++,k++;
    }
    while(j<=high){
        B[k]=A[j];
        j++,k++;
    }
    for(int i=low;i<=high;i++){
        A[i]=B[i];
    }

}
void mergeSort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);

    }

}





void printArray(int A[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

}




int main()
{
    int A[]= {14,67,5,23,1,9};
    int n=6;
    printArray(A,n);
    mergeSort(A,0,n-1);
    printArray(A,n);

}
