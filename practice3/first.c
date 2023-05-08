#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=5;
    int array[5]={2,5,12,1,7};
    printf("hello");
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j=n-1-i;j++){
            if(array[j]>array[j+1]){
                int s=array[j];
                array[j]=array[j+1];
                array[j+1]=s;
                
                
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d",array[i]);
        
    }
    
}
