// dijkshtrasAlgo for weighted directed graph
# include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int minVertex(int v,int dist[],int vset[]){
    int min=9999 , index;
    for(int i=0;i<v;i++){
        if(vset[i]==0 && dist[i]<min){
            min=dist[i];
            index =i;
        }
    }
    return index;

}
void display(int v,int dist[]){
    printf("Vertex\t  Distance from source");
    for(int i=0;i<v;i++){
        printf("%d\t  %d\n",i,dist[i]);

    }
}
void dijkshtrasAlgo(int v ,int G[v][v],int source){
    int u;
    int vset[10], dist[10]; //distane and visited set arrays
    for(int i=0;i<v;i++){
        dist[i]=999; //initialize distance array =999 ie infitnity
        vset[i]=0;
    }
    dist[source]=0;
    for(int i=0;i<v-1;i++){
        u = minVertex(v,dist,vset);
        vset[u]=1; 

        for(int j=0;j<v;j++){
        if(vset[j]!=1 && G[u][j] &&  dist[u]+ G[u][j] < dist[j]){
            dist[j]=dist[u]+ G[u][j];
        }
    } 

    }
    
    display(v,dist);

}
 

int main(){
    int v;
    int source;

    printf("Enter number of vertices : ");
    scanf("%d",&v);
    int G[v][v];
    printf("Enter adj Matrix : \n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("AdjMatrix[%d][%d]: ",i,j);
            scanf("%d",&G[i][j]);

        }
       

    }

    // 0------>1\
    // |     / |  \  
    // |   /   |   4  
    // | /     |  /
    // 2------->3
    printf("Enter the source : ");
    scanf("%d",&source);
    dijkshtrasAlgo(v,G,source);


}