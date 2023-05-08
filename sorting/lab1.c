#include <stdio.h>
#include <stdlib.h>
struct stud{
    char name[20];
    long salary;
    int emp_id;
    
    
};
void heapify(struct stud a[], int n, int i)  
{  
    int largest = i;  
    int left = 2 * i + 1; 
    int right = 2 * i + 2;   
     
    if (left < n && a[left].emp_id > a[largest].emp_id)  
        largest = left;  
      
    if (right < n && a[right].emp_id > a[largest].emp_id)  
        largest = right;  
     
    if (largest != i) {  
        
        struct stud temp;  
        temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  
  
void Hsort(struct stud a[], int n)  

{  
    int swap=0;
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    
    for (int i = n - 1; i >= 0; i--) {  
        swap++;
          
        struct stud temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  

    printf("\nSWAPS IN HEAP SORT: %d\n", swap);
}  

void Print(struct stud list[],int n){
    printf("\n\nEmp_ID \tEmp Name\tSalary\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%d\n",list[i].emp_id,list[i].name,list[i].salary);
    }
    
}
int main(){
    struct stud list[10];
    int n;
    
    printf("enter number of records: ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
    
        printf("\n Enter Employee %d record:",i+1);

        printf("\n Enter emp_id: ");
        scanf("%d",&list[i].emp_id);

        printf("\n Enter name: ");
        scanf("%s",&list[i].name);
        
        printf("\n Enter salary: ");
        scanf("%d",&list[i].salary);
        
        
        
    }
    printf("\nBefore sorting: ");
    printf("\n\nEmp_ID \tEmp Name\tSalary\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%d\n",list[i].emp_id,list[i].name,list[i].salary);
        printf("");
    }
    printf("After sorting with Heap sort: ");
    Hsort(list,n-1);
    Print(list,n);
}