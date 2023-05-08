#include <stdio.h>
int partition(int A[],int low,int high)
{
    int i,j;
    int pivot=A[low];
    i=low+1;
    j=high;
    int temp;
    do
    {
        while(A[i]<=pivot) //find element less than pivot i++
        {
            i++;
        }
        while(A[j]>pivot) //find element more than pivot
        {
            j--;
        }
        if(i<=j) //if i and j cross swap them
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    while(i<j);
    //swap the pivot with j
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;

    return j;

}
void QuickSort(int A[],int low,int high)
{
    int index;
    if(low<high)
    {
        index=partition(A,low,high);
        QuickSort(A,low,index);
        QuickSort(A,index+1,high);
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
    QuickSort(A,0,n-1);
    printArray(A,n);
}
