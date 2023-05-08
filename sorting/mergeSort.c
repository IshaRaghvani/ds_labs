#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int left,int mid,int right){

    int n1=(mid-left)+1; 
    int n2=right-mid; //mid=3
    int a[n1];
    int b[n2];  //temporary arrays
    for(int i=0; i<n1; i++){
        //filling elements from actual array to arra a
        // a[0]<-arr[0]
        // a[1]<-arr[1]
        // ---------a[3]<-arr[4]
        a[i]=arr[left+i]; 
    }
    for(int j=0; j<n2; j++){
        //b[0]<-b[3+0 + 1]<- b[4]
        //b[1]<-b[5]
        //-----------b[4]<-b[7]
        b[j]=arr[mid +1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++;
        }
        else{
            arr[k]=b[j];
            
            j++;
        }
        k++;
    } // even after this loop elements might be present
    //so add thses elements also
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
    
  
}

void mergeSort(int arr[],int left,int right){

    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    

    }
  
}

void Print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        
    }
    
}
int main(){
    int n=4;
    int arr[4]={5,60,2,21};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("%d ",arr_size);
    printf("Unsorted array: \n ");
    Print(arr,n);
    
    printf("Sorted array:    ");
    mergeSort(arr,0,n-1);
    
    Print(arr,n);
    return(0);
    

    
    
}

