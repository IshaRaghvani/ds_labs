#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//BFS AND DFS TRAVERSAL USNG ADJACENCY LISTS

struct node{
    int data;
    struct node* next;

};
struct graph{
    int num_vertices;
    struct node* *adjList;
    int *visited;
};

int stack[10];
int top=-1;
void push(int data){
    stack[++top]=data;
}
int pop(){
    return(stack[top--]);
}
bool isEmpty(){
    return(top==-1);
}

struct node* createNode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    return n;

};
struct graph* createGraph(int vertices){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->num_vertices=vertices;
    g->visited=malloc(vertices * sizeof(int));

    g->adjList=malloc(vertices * sizeof(struct node));

    for(int i = 0; i < vertices; i++){
        g->adjList[i] = NULL;
        g->visited[i] = 0;
    }

    return g;

};
void addEdges(struct graph* g,int source,int destination){
    //s->d
    struct node* n1=createNode(destination);
    n1->next=g->adjList[source];
    g->adjList[source]=n1;

    //d->s
    struct node* n2=createNode(source);
    n2->next=g->adjList[destination];
    g->adjList[destination]=n2;

}

void print(struct graph* g){
    int v;

    for(int v=0;v<g->num_vertices;v++){
        struct node* temp=g->adjList[v];
        printf("\n%d : ",v);
        while(temp){
            printf("%d-> ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }


}
void DFS(struct graph* g , int start){

    push(start);

    while(!isEmpty()){
            int curr=stack[top];
            pop();
            if(g->visited[curr]==0){
                    printf("%d ",curr);
                    g->visited[curr]=1;

            }

            struct node* adj=g->adjList[curr];
            struct node* temp=adj;
            while(temp){
                int adjvertex=temp->data;
                if(g->visited[adjvertex]==0){
                    push(adjvertex);

                }
                temp=temp->next;
            }


    }


}
int main(){

    struct graph* g=createGraph(5);
    addEdges(g,0,1);
    addEdges(g,0,2);
    addEdges(g,0,3);

    addEdges(g,1,4);

    addEdges(g,2,4);

    addEdges(g,3,4);


    printf("Adjcency List : ");
    print(g);

    printf("\nDFS Traversal is : ");
    DFS(g,0);


}


