# include <stdio.h>

#include <stdlib.h>

void init(int V, int arr[][V]){
    for(int i=0; i<V;i++){
        for(int j=0;j<V;j++){
            arr[i][j]=0;
        }
    }
}

void edges(int V,int arr[][V],int i,int j){
    arr[i][j]=1;
    arr[j][i]=1;
}
void print(int V,int arr[][V]){
    printf("   | ");
    for(int k=0;k<V;k++){
        printf("%d ",k);
    }
    
    printf("\n");
    printf("---------------\n");
    for(int i=0; i<V;i++){
        printf("%d  | ",i);
        for(int j=0;j<V;j++){
            
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int V;
    printf("Enter no. of vertices: ");
    
    

    // 0--------2
    // |      /  \
    // |    /     4
    // |  /      /
    // 1--------3



    
    scanf("%d",&V);
    int adjMatrix[V][V];
    init(V,adjMatrix);
    edges(V,adjMatrix,0,1);
    edges(V,adjMatrix,0,2);
    
    edges(V,adjMatrix,1,2);
    edges(V,adjMatrix,2,3);
    edges(V,adjMatrix,2,4);
    edges(V,adjMatrix,4,3);
    edges(V,adjMatrix,1,3);

    print(V,adjMatrix);

    return 0;
}