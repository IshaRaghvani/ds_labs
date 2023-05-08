#include <stdio.h>


void SelectionSort(int A[],int n){
    int min,temp;
    for(int i=0;i<=n-1;i++){
        min=i;
        for(int j=i+1;j<=n-1;j++){
            if(A[j]<A[min]){
                    min=j;

            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
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
    SelectionSort(A,n);
    printArray(A,n);
}
