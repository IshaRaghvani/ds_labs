# include <stdio.h>
int binarysearch(int arr[],int x,int low,int n){
    int mid;
    int high=n-1;

    while(low<=high){
        mid=(low+high)/2;
        if(x==arr[mid]){
            return mid;
        }
        else if(x>arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n=7;
    int x=34;
    int arr[7]={3,12,9,30,11,34,8};
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    // printf("Enter element to search: \n");
    // scanf("%d ",&x);

    int num = binarysearch(arr,x,0,n-1);
    if(num==-1){
        printf("element not found");
    }
    else{
        printf("element found at index %d ",num+1);
    }
    return 0;
}
