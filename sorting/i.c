#include <stdio.h>
struct employee
{
    int emp_no;
    float emp_sal;
    char emp_nm[20];
};
int count1 = 0;
int count = 0;
void swap(struct employee a[], int i, int j)
{
    struct employee temp = a[j];
    a[j] = a[i];
    a[i] = temp;
    count1++;
}
void hswap(struct employee a[], int i, int j)
{
    struct employee temp = a[j];
    a[j] = a[i];
    a[i] = temp;
    count++;
}

int partition(struct employee a[], int low, int high)
{
    int pivot = low;
    int i = low, j = high, count = 0;
    while (i < j)
    {
        while (a[i].emp_no < a[pivot].emp_no)
        {
            i++;
            }
        while (a[j].emp_no > a[pivot].emp_no)
        {
            j--;
        }
        if (i < j)
        {
            swap(a, i, j);
        }
    }
    swap(a, pivot, j);
    return j;
}
void quicksort(struct employee a[], int low, int high)
{
    int i = low, j = high;
    if (i < j)
    {
        j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}
void merge(struct employee a[], int low, int k, int high)
{
    struct employee result[20];
    int i = low, j = k + 1, l = 0;
    while (i <= k && j <= high)
    {
        if (a[i].emp_no < a[j].emp_no)
        {
            result[l]= a[i];
            i++;
            l++;
        }
        else
        {
            result[l] = a[j];
            j++;
            l++;
        }
    }
    while (i <= k)
    {
        result[l] = a[i];

        i++;
        l++;
    }
    while (j <= high)
    {
        result[l] = a[j];
        j++;
        l++;
    }
    for (int i = low, j = 0; i <= high; i++, j++)
    {
        a[i] = result[j];
    }
}
void mergesort(struct employee a[], int low, int high)
{

    if (low < high)
    {
        int k = (low + high) / 2;
        mergesort(a, low, k);
        mergesort(a, k + 1, high);
        merge(a, low, k, high);
    }
}
void heapify(struct employee arr[], int N, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left].emp_no > arr[largest].emp_no)

        largest = left;
    if (right < N && arr[right].emp_no > arr[largest].emp_no)

        largest = right;
    if (i != largest)
    {
        hswap(arr, i, largest);
        heapify(arr, N, largest);
    }
}

void heapSort(struct employee arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {
        hswap(arr, 0, i);
        heapify(arr, i, 0);
    }
}
void Print(struct employee s[],int n){
    printf("\n\nEmp_ID \tEmp Name\tSalary\n");
    for(int i=0;i<n;i++){
        printf("%d\t%f\t%s\n",s[i].emp_no,s[i].emp_sal,s[i].emp_nm);
    }
    
}

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    struct employee s[n];

    for (int i = 0; i < n; i++)
    {
        
        printf("\n Enter Employee %d record:",i+1);

        printf("\n Enter emp_id: ");
        scanf("%d",&s[i].emp_no);

        printf("\n Enter salary: ");
        scanf("%f",&s[i].emp_sal);
        
        printf("\n Enter name: ");
        scanf("%s",&s[i].emp_nm);
    }
    printf("\nBefore sorting: ");
    printf("\n\nEmp_ID \tSalary\t\tEmp Name\n");
    for(int i=0;i<n;i++){
        printf("%d\t%f\t%s\n",s[i].emp_no,s[i].emp_sal,s[i].emp_nm);
        printf("");
    }
    quicksort(s, 0, n - 1);
    
    printf("Quick sort:\n");
    printf("\n\nEmp_ID \tSalary\t\tEmp Name\n");
    for(int i=0;i<n;i++){

        printf("%d\t%f\t%s\n",s[i].emp_no,s[i].emp_sal,s[i].emp_nm);
        printf("");
    }
    printf("The total number of swaps in quick sort are %d ",count1);
    heapSort(s,n);
    printf("\nHeap sort:\n");
    Print(s,n);
    printf("The total number of swaps in heap sort are %d ",count);
    printf("\nMerge sort:\n");
    mergesort(s,0,n-1);
    Print(s,n);


    return 0;
}

