#include <stdio.h>
#include <stdlib.h>
struct stud{
    char name[20];
    int rollno;
    float cpi;
    
    
};
void heapify(struct stud a[], int n, int i)  
{  
    int largest = i;  
    int left = 2 * i + 1; 
    int right = 2 * i + 2;   
     
    if (left < n && a[left].rollno > a[largest].rollno)  
        largest = left;  
      
    if (right < n && a[right].rollno > a[largest].rollno)  
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
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    
    for (int i = n - 1; i >= 0; i--) {  
          
        struct stud temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  

void merge(struct stud list[],int left,int mid,int right){
    int n1=(mid-left)+1;
    int n2=right-mid;
    struct stud a[n1];
    struct stud b[n2];
    for(int i=0;i<n1;i++){
        a[i].rollno=list[left+i].rollno;
        
    }
    for(int j=0;j<n2;j++){
        b[j].rollno=list[mid+1+j].rollno;
        
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(a[i].rollno<=b[j].rollno){
            list[k].rollno=a[i].rollno;
            i++;
        }
        else{
            list[k].rollno=b[j].rollno;
            
            j++;
        }
        k++;
        while(i<n1){
        list[k].rollno=a[i].rollno;
        i++;
        k++;
    }
    while(j<n2){
        list[k].rollno=b[j].rollno;
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


void QSort(struct stud l[],int low,int high){
    int i,j,pivot;
    struct stud temp;
    pivot=low;
    i=low;
    j=high;
    while(i<j){
        while(l[i].rollno<=l[pivot].rollno && i<high){
            i++;
        }
        while(l[j].rollno>l[pivot].rollno){
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
    for(int i=0;i<n;++i){
        for(int j=0;j<n-1;++j){
            if(list[j].rollno>list[j+1].rollno){
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}
void Print(struct stud list[],int n){
    printf("\n\nName\tCPI\tRoll no\n");
    for(int i=0;i<n;i++){
        printf("%s\t%f\t%d\n",list[i].name,list[i].cpi,list[i].rollno);
    }
}
int main(){
    struct stud list[10];
    int n;
    
    printf("enter number of records: ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
    
        printf("\n Enter student record %d :",i+1);
        printf("\n Enter name: ");
        scanf("%s",&list[i].name);
        
        printf("\n Enter cpi: ");
        scanf("%f",&list[i].cpi);
        
        printf("\n Enter roll no: ");
        scanf("%d",&list[i].rollno);
        
    }
    printf("\nBefore sorting: ");
    printf("\n\nName\tCPI\tRoll no\n");
    for(int i=0;i<n;i++){
        printf("%s\t%f\t%d\n",list[i].name,list[i].cpi,list[i].rollno);
        printf("");
    }
    printf("After sorting with bubble sort: ");
    BSort(list,n);
    Print(list,n);
    printf("After sorting with Quick sort: ");
    QSort(list,0,n-1);
    Print(list,n);
    printf("After sorting with Merge sort: ");
    Msort(list,0,n-1);
    Print(list,n);
    printf("After sorting with Heap sort: ");
    Hsort(list,n-1);
    Print(list,n);
    
}

