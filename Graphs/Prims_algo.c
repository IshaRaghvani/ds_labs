# include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int minKey(int v ,int key[],int set[]){
    int min=999,index;
    for(int i=0;i<v;i++){
        if(set[i]==0 && key[i]<min){
            min=key[i];
            index=i;
        }

    }
    return index;
}
void displayMST(int v,int parent[],int G[v][v]){
    printf("Edge  \t   Weight \n");
    for(int i=0;i<v;i++){
        printf("%d -- %d  \t  %d \n",parent[i],i,G[i][parent[i]]);

    }
}
void prims(int v,int G[v][v]){
    int parent[10],key[10],set[10],u;
    for(int i=0;i<v;i++){
        key[i]=999;
        set[i]=0;
    }
    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<v-1;i++){
        u= minKey(v,key,set);
        set[u]=1; //visited node after finding min edge

        for(int j=0;j<v;j++){
            if(G[u][j]!=998 && set[j]==0 && G[u][j]<key[j]){

                parent[j]=u;
               key[j]=G[u][j];
            }

        }
         
    }
    displayMST(v,parent,G);

}

int main(){
    int i,j, v,adjMatrix[10][10];
    printf("Enter no. of vertices:  ");
    scanf("%d",&v);
    printf("Enter the adj matrix: \n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("adjMatrix[%d][%d]",i,j);
            scanf("%d",&adjMatrix[i][j]);
            
        }
    }
     prims(v,adjMatrix);
    printf("Adjacency Matrix is: \n");
    for(i=0;i<v;i++){
        printf("%d ",i);
        for(j=0;j<v;j++){
            printf("%d ",adjMatrix[i][j]);
           
        }
        printf("\n");
    }






}