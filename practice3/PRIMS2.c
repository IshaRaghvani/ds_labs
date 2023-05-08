#include <stdio.h>
#include <stdlib.h>



struct node{
    int vertex;
    int weight;
    struct node* next;
};
struct graph{
    int numvertices;
    struct node* *adjlist;

};


struct node* create(int vertex,int weight){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=vertex;
    newnode->weight=weight;
    newnode->next=NULL;

    return newnode;
}
struct graph* createGraph(int vertices){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->numvertices=vertices;
    g->adjlist=malloc(sizeof(struct node));
    for(int i=0;i<vertices;i++){
        g->adjlist[i]=NULL;
    }

    return g;

}

void addEdges(struct graph* g,int src,int dest,int w){

    struct node* n1=create(dest,w);
    n1->next=g->adjlist[src];
    g->adjlist[src]=n1;

    struct node* n2=create(src,w);
    n2->next=g->adjlist[dest];
    g->adjlist[dest]=n2;
}


int minKey(int set[],int weight_key[],int v){
    int min=999;
    int index=0;
    for(int i=0;i<v;i++){
        if(set[v]==0 && min>weight_key[i]){
            min=weight_key[i];
            index=i;
        }
    }
    return index;

}


void prims(struct graph* g,int start){
    int parent[g->numvertices],set[g->numvertices],weight_key[g->numvertices];
    for(int i=0;i<g->numvertices;i++){
        set[i]=0;
        weight_key[i]=999;

    }
    set[start]=1;
    parent[start]=-1;

    for(int i=0;i<g->numvertices-1;i++){
        int u=minKey(set,weight_key,g->numvertices);
        set[u]=1;

        struct node* temp=g->adjlist[u];
        while(temp){
            int v=temp->vertex;
            int w=temp->weight;
            if(set[v]==0 && w<weight_key[v]){
                weight_key[v]=w;
                parent[v]=u;
            }
            temp=temp->next;
        }
    }
    printf("\nMinimum spanning tree:");
    for(int i=0;i<g->numvertices;i++){
        printf("V:%d  [%d %d] , w=%d ",i,parent[i],i,weight_key[i]);
    }

}
void printGraph(struct graph* g){

    for(int i=0;i<g->numvertices;i++){
        struct node* temp=g->adjlist[i];
        printf("Vertex: %d",i);
        while(temp){
            printf("%d w[%d]-> ",temp->vertex,temp->weight);
            temp=temp->next;
        }


    }

}
int main(){
    printf("start");


    struct graph* g=createGraph(5);
    printf("ddd");
    addEdges(g,0,1,1);
    addEdges(g,0,2,2);
    addEdges(g,0,3,2);
    addEdges(g,1,4,4);
    addEdges(g,3,4,3);
    addEdges(g,2,4,5);
    printf("jahaj");
    printGraph(g);

    prims(g,0);
    return 0;


}
