#include <stdio.h>  

// function that consider first element as pivot,  
// place the pivot at its exact position, and place  
// smaller elements to left of pivot and greater  
// elements to right of pivot.  
int partition(int arr[], int low, int high)  
{  
    int count=0;
    int pivot = arr[low]; // pivot element  
    int i = low + 1; // index of smaller element  
    int j = high; // index of larger element  
  
    while (i <= j)  
    {  
        // If current element is smaller than or equal to pivot  
        if (arr[i] <= pivot)  
            i++;  
        // If current element is greater than pivot  
        else if (arr[j] > pivot)  
            j--;  
        // Swap arr[i] and arr[j]  
        else  
        {  
            int temp = arr[i];  
            arr[i] = arr[j];  
            arr[j] = temp;  
            i++;  
            j--; 
            count++; 
        }  
    }  
    // Swap pivot element with element at index j  
    int temp = arr[low];  
    arr[low] = arr[j];  
    arr[j] = temp;  
    return j;  
    count++;
    printf("\ncount of swaps is : %d",count);
}  
  
// function to implement quick sort  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        // Find pivot element, such that element left to it are smaller  
        // and elements right to it are greater  
        int pi = partition(arr, low, high);  
        // Sort elements before and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
// function to print an array  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
}  
  
// Driver program to test above functions  
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    printf("Array before sorting: \n");  
    printArray(arr, n);  
    quickSort(arr, 0, n - 1);  
    printf("\nArray after sorting: \n");  
    printArray(arr, n);  
    return 0;  
}  
