#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int src;
    int dest;
    int weight;
};
struct graph{
    int numvertices;
    int numedges;
    struct Edge edge[100];
};
struct uniFind{
    int parent[100];
    int rank[100];
};

void innitUnion(struct uniFind* uf,int vertex){

    for(int i=0;i<vertex;i++){
        uf->parent[i]=i;
        uf->rank[i]=0;
    }

}

int findParent(struct uniFind* uf,int vertex1){
    if(uf->parent[vertex1]!=vertex1){
        uf->parent[vertex1]=findParent(uf,uf->parent[vertex1]);
    }
    return uf->parent[vertex1];
}
void unionFind(struct uniFind* uf,int u,int v){
    int v1=findParent(uf,u);
    int v2=findParent(uf,v);
    if(uf->rank[v1]<uf->rank[v2]){
        uf->parent[v1]=v2;
    }
    else if(uf->rank[v1]>uf->rank[v2]){
        uf->parent[v2]=v1;
    }
    else{
        uf->parent[v2]=v1;
        uf->rank[v1]++;
    }
}

void BuubleSort(struct Edge *edge, int no_of_edges){

    for(int i=0;i<no_of_edges;i++){
        for(int j=0;j<no_of_edges-i-1;j++){

            if(edge[j].weight>edge[j+1].weight){
                struct Edge temp= edge[j];
                edge[j]=edge[j+1];
                edge[j+1]=temp;
            }

        }
    }

}

void kruskals(struct graph* g,struct uniFind *uf){

    int i=0, num_edges=0;
    innitUnion(uf,g->numvertices);
    BuubleSort(g->edge,g->numedges);
   
    while(num_edges <g->numvertices-1 && i<g->numedges){
        struct Edge e=g->edge[i];
        
        int v1=findParent(uf,e.src);
        int v2=findParent(uf,e.dest);
        
        if(v1!=v2){
            unionFind(uf,e.src,e.dest);
            printf("(%d %d )   w: %d\n",e.src,e.dest,e.weight);
        }
        i++;

    }

}
int main(){


    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    struct uniFind* uf=(struct uniFind*)malloc(sizeof(struct uniFind));
    printf("\nEnter no of vertices: ");
    scanf("%d",&g->numvertices);
    printf("\nEnter no of edges: ");
    scanf("%d",&g->numedges);
    printf("\nEnter src , dest , weight: ");
    for(int i=0;i<g->numedges;i++){
        printf("\nEdges[%d]: ",i);
        scanf("%d %d %d",&g->edge[i].src,&g->edge[i].dest,&g->edge[i].weight);
    }
    printf("\nKrushkals:  ");
    kruskals(g,uf);


    return 0;

}