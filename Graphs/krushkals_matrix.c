#include <stdio.h>


int parent[10];

int find(int i){
    while(parent[i]){
        i=parent[i];
    }
    return i;

}
int Union(int v,int u){
    if(v!=u){
        parent[v]=u;
        return 1;
    }
    return 0;
}
int main()
{
    int G[10][10];
    int vertices, edges=1,a,b,v,u,min;
    int cost=0;
    printf("\nEnter no of vertices: ");
    scanf("%d", &vertices);
    
    
    printf("\nEnter adj matrix: ");
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            printf("\nG[%d][%d]: ", i, j);
            scanf("%d", &G[i][j]);
            if (G[i][j] == 0)
            {
                G[i][j] = 999;
            }
        }
    }
    
    
    while (edges < vertices)
    {
        min = 999;
       
        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                if(G[i][j]<min){
                    min=G[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(Union(u,v)){

            printf("\nEdge: %d [%d %d]   w: %d",edges++,u,v,min);
            cost+=min;
        }
        
        G[a][b]=G[b][a]=999;
    }
    printf("\nmin cost: %d",cost);


    return 0;
    
}