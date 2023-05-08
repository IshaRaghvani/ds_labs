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
    g->adjlist=(struct node**)malloc(vertices* sizeof(struct node*));
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
int minkey(int visited[],int distance[],int v){
    int min=999;
    int index=0;
    for(int i=0;i<v-1;i++){
        if(visited[i]==0 && distance[i]<min){
            min=distance[i];
            index=i;
        }
    }
    return index;
}

void dijkstraw(struct graph* g){
    int visited[10],distance[10];
    for(int i=0;i<g->numvertices;i++){
        visited[i]=0;
        distance[i]=998;
    }
    
    distance[0]=0;

    for(int i=0;i<g->numvertices;i++){
        int u=minkey(visited,distance,g->numvertices);
        visited[u]=1;

        struct node* temp=g->adjlist[u];
        while(temp){
            int v=temp->vertex;
            int w=temp->weight;
            if(visited[v]!=1 && distance[u]+w<=distance[v]){
                distance[v]=distance[u]+w;
                
                
            }
            temp=temp->next;
        }
    }
    printf("\nMininmun spanning tree:");
    for(int i=0;i<g->numvertices;i++){
        printf("\n[%d]  weight: %d",i,distance[i]);
    }
}

void print(struct graph* g){

    for(int i=0;i<g->numvertices;i++){
        struct node* temp=g->adjlist[i];
        printf("\nVertex: %d ",i);
        while(temp){
            printf("(%d w[%d])-> ",temp->vertex,temp->weight);
            temp=temp->next;
        }
        printf("NULL\n");
        

        
    }

}
int main(){

    struct graph* g=createGraph(5);
    
    addEdges(g,0,1,1);
    addEdges(g,0,2,2);
    addEdges(g,0,3,2);
    addEdges(g,1,4,4);
    addEdges(g,3,4,3);
    
    
    print(g);

    dijkstraw(g);

    
}