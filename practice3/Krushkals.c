#include <stdio.h>

int parent[10];

int find(int i){
        while(parent[i])
            i=parent[i];
            return i;


    }
    int uni(int i,int j){
        if(i!=j){
            parent[j]=i;
            return 1;
        }
        return 0;


    }

int main(){
    int G[10][10];
    int ver,e=1;
    int a,b,u,v,i,j;
    int min;
    int cost=0;
    int uni(int,int);
    int find(int);




    printf("Enter number of vertices: ");
    scanf("%d",&ver);
    for(i=1;i<=ver;i++){
        for(j=1;j<=ver;j++){
                printf("G[%d][%d]: ",i,j);
                scanf("%d",&G[i][j]);
                if(G[i][j]==0){
                    G[i][j]=999;
                }


        }
    }

    while(e<ver){
        for(i=1,min=999;i<=ver;i++){
            for(j=1;j<=ver;j++){
                if(G[i][j]<min){
                    min=G[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);

        if(uni(u,v)){

            printf("%d edge [%d][%d] -> %d\n",e++,a,b,min);
            cost+=min;


        }
        G[a][b]=G[b][a]=999;
    }
    printf("Minimum cost: %d",cost);
    getch();









}
