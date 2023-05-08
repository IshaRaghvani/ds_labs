# include <stdio.h>

#include <stdlib.h>

struct node{
    int vertex;
    struct node* next;
};
struct graph{
    int numVertices;
    struct node **adjList;
};

struct node* create(int vertex_data){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->vertex=vertex_data;
    newnode->next=NULL;
    return newnode;
}

struct graph *createGraph(int num_vertices){

    struct graph *g=(struct graph*)malloc(sizeof(struct graph)); //allocate for graph
    g->numVertices=num_vertices;
    g->adjList=malloc(num_vertices * sizeof(struct graph));  //allocate memory for each element of array of size no. of vertices

    for(int i=0;i<num_vertices;i++){
        g->adjList[i]=NULL;
    }
    return g;
}

void addEdge(struct graph *g, int source , int destination){

    // s->d
    struct node* newNode=create(destination);
    newNode->next=g->adjList[source];
    g->adjList[source]=newNode;

    //d->s
    struct node* newNode2=create(source);
    newNode2->next=g->adjList[destination];
    g->adjList[destination]=newNode2;

}

void printGraph(struct graph *g){

    for(int i=0;i<g->numVertices;i++){
        struct node* temp=g->adjList[i];
        printf("\nVertex: %d\n",i);

        while(temp){
            printf("%d-> ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");

    }

}

int main(){

    struct graph* g= createGraph(4);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,3);
    addEdge(g,2,3);
    addEdge(g,1,2);

    printGraph(g);
}