#include <stdio.h>

int minkey(int set[], int weight_key[], int v)
{

    int min = 998;
    int index = 0;
    for (int i = 0; i < v; i++)
    {
        if (set[i] == 0 && weight_key[i] < min)
        {
            min = weight_key[i];
            index = i;
        }
    }
    return index;
}
void prims(int G[10][10], int v)
{

    int parent[10], set[10], weight_key[10];
    for (int i = 0; i < v; i++)
    {

        set[i] = 0;
        weight_key[i] = 999;
    }
    parent[0] = -1;
    set[0] = 1;

    for (int i = 0; i < v - 1; i++)
    {
        int u = minkey(set,weight_key,v);
        set[u] = 1;

        for (int j = 0; j < v; j++)
        {
            if (G[u][j] != 999 && set[j] == 0 && G[u][j] < weight_key[u])
            {
                weight_key[j] = G[u][j];
                parent[j] = u;
            }
        }
    }
    printf("\nMinimum spanning tree:");
    for (int i = 1; i < v; i++)
    {
        printf("\nVertex: %d [%d %d ]   weight: %d",i,parent[i],i,weight_key[i]);

    }
}
int main(){

    int G[10][10];
    int v;
    printf("Number of vertices: ");
    scanf("%d",&v);
    printf("\nEnter the matrix: ");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("G[%d][%d]: ",i,j);
            scanf("%d",&G[i][j]);
        }
    }
    prims(G,v);






    return 0;

}