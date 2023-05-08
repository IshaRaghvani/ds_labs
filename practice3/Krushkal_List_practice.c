#include <stdio.h>
#include <stdlib.h>


struct Edge{
    int src;
    int dest;
    int weight;

};
struct Graph{
    int numVertices;
    int numEdges;
    struct Edge e[100];


};

struct uniFind{
    int parent[100]; //parent node of each node
    int rank[100];  // keeps track of the depth of the node
};




void initUnionFind(struct uniFind* uf,int vertex){
    for(int i=0;i<vertex;i++){
        uf->parent[i]=i;
        uf->rank[i]=0;
    }
}
int find(struct uniFind *uf, int v){
    if(uf->parent[v]!=v){
        uf->parent[v]=find(uf,uf->parent[v]);
    }
    return(uf->parent[v]);


}
void Union(struct uniFind *uf, int vertex1,int vertex2){

    int u=find(uf,vertex1);
    int v=find(uf,vertex2);

    if(uf->rank[u]<uf->rank[v]){
        uf->parent[u]=v;
    }
    else if(uf->rank[u]>uf->rank[v]){
        uf->parent[v]=u;
    }
    else{
        uf->parent[v]=u;
        uf->rank[u]++;
    }
}

void BubbleSort(struct Edge*e,int numEdges){
    for(int i=0;i<numEdges-1;i++){
        for(int j=0;j<numEdges-i-1;j++){
            if(e[j].weight > e[j+1].weight){
                struct Edge temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }

}
void Krushkals(struct Graph *g, struct uniFind* uf){
    int i=0;
    int numEdges=0;
    initUnionFind(uf,g->numVertices);
    BubbleSort(g->e,g->numEdges);

    while(numEdges < g->numVertices-1 && i<g->numEdges){

            struct Edge edge = g->e[i];
            int u=find(uf,edge.src);
            int v=find(uf,edge.dest);

            if(u!=v){

                Union(uf,edge.src,edge.dest);
                printf("(%d %d) weight: %d\n",edge.src,edge.dest,edge.weight);
            }
            i++;

    }

}



int main(){
    struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
    struct uniFind *uf=(struct uniFind*)malloc(sizeof(struct uniFind));

    printf("\nEnter number of vertices: ");
    scanf("%d",&g->numVertices);

    printf("\nEnter number of Edges: ");
    scanf("%d",&g->numEdges);

    printf("\nEnter source , destination and weight: ");
    for(int i=0;i<g->numEdges;i++){
            printf("\nEdge %d: ",i);
    scanf("%d%d%d",&g->e[i].src,&g->e[i].dest,&g->e[i].weight);

    }

    printf("\nKrushkals algorithm: \n");
    Krushkals(g,uf);

    free(g->e);
    free(g);
    free(uf);

}


