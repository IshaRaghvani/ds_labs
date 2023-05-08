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

    //printf("\nSWAPS IN HEAP SORT: %d\n", swap);
}  

void merge(struct stud list[],int left,int mid,int right)
{
    
    
    int n1=(mid-left)+1;
    int n2=right-mid;
    struct stud a[n1];
    struct stud b[n2];
    for(int i=0;i<n1;i++){
        a[i].emp_id=list[left+i].emp_id;
        
    }
    for(int j=0;j<n2;j++){
        b[j].emp_id=list[mid+1+j].emp_id;
        
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(a[i].emp_id<=b[j].emp_id){
            list[k].emp_id=a[i].emp_id;
            i++;
            
        }
        else{
            list[k].emp_id=b[j].emp_id;
            j++;
            

            
        }
        k++;
        while(i<n1){
        list[k].emp_id=a[i].emp_id;
        i++;
        k++;
    }
    while(j<n2)
    {
        list[k].emp_id=b[j].emp_id;
        j++;
        k++;
    
    } 

    }
    
}
void Msort(struct stud list[],int left,int right){
    
    if(left<right){
        int mid=(left+right)/2;
        Msort(list,left,mid);
        Msort(list,mid+1,right);
        merge(list,left,mid,right);
    }
}


int QSort(struct stud l[],int low,int high){
    int i,j,pivot;
    struct stud temp;
    pivot=low;
    i=low;
    j=high;
    int swap=0;
    while(i<j)
    {
        while(l[i].emp_id<=l[pivot].emp_id && i<high){
            swap++;
            i++;   
        }
        while(l[j].emp_id>l[pivot].emp_id){
            swap++;
            j--;    
        }
        if(i<j){
            temp= l[i];
            l[i]=l[j];
            l[j]=temp;
        }
        struct stud temp1;
        temp1=l[pivot];
        l[pivot]=l[j];
        l[j]=temp1;
        QSort(l,low,j-1);
        QSort(l,j+1,high);
        
    
    }
    
    
    

}
void BSort(struct stud list[],int n){
    struct stud temp;
    int swap=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n-1;++j){
            if(list[j].emp_id>list[j+1].emp_id){
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
                swap+=1;
            }
        }
    }
    //printf("\nSWAPS IN BUBBLE SORT: %d",swap);
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
    printf("\nAfter sorting with Bubble sort: ");
    BSort(list,n);
    Print(list,n);
    printf("\nSWAPS ARE \n: %d",swap);
    printf("\nAfter sorting with Quick sort: ");
    QSort(list,0,n-1);
    Print(list,n);
    printf("\nSWAPS ARE \n: %d",swap);
    printf("After sorting with Merge sort: ");
    Msort(list,0,n-1);
    Print(list,n);
    printf("After sorting with Heap sort: ");
    Hsort(list,n-1);
    Print(list,n);
    printf("\nSWAPS ARE \n: %d",swap);
    return 0;
    
}

