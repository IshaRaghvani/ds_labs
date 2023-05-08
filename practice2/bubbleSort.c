
#include <stdio.h>

void BubbleSort(int A[],int n)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            //swapping
            if(A[j]>A[j+1])
            {

                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;


            }

        }

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
    BubbleSort(A,n);
    printArray(A,n);
}
