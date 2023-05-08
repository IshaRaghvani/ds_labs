#include <stdio.h>


void InsertionSort(int A[],int n){
    int j,key;
    for(int i=1;i<=n-1;i++){
        key=A[i];
        j=i-1;
        while(key<A[j] && j>=0){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
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
    InsertionSort(A,n);
    printArray(A,n);
}
