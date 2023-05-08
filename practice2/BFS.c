#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
//BFS AND DFS TRAVERSAL USNG ADJACENCY LISTS

struct node
{
    int data;
    struct node* next;

};
struct graph
{
    int num_vertices;
    struct node* *adjList;
    int *visited;
};
struct queue
{
    int front;
    int rear;
    int items[SIZE];
};
struct queue* createQueue(int size)
{
    struct queue*q=(struct queue*)malloc(sizeof(struct queue));
    q->front=0;
    q->rear=-1;


    return q;
};

void enqueue(struct queue *q,int value)
{
    if(q->rear==SIZE-1)
    {
        printf("Queue is full");
    }
    else
    {


        q->rear++;
        q->items[q->rear]=value;
    }

}

int isQueueEmpty(struct queue *q)
{
    if(q->rear==-1)
        return 1;
    else
        return 0;
}


int dequeue(struct queue *q)
{
    int item;
    if(isQueueEmpty(q))
    {
        printf("Queue is empty");

    }
    else
    {
        item=q->items[q->front];
        q->front++;
    }
    return item;
}






struct node* createNode(int data)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    return n;

};
struct graph* createGraph(int vertices)
{
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->num_vertices=vertices;
    g->visited=malloc(vertices * sizeof(int));

    g->adjList=malloc(vertices * sizeof(struct node));

    for(int i = 0; i < vertices; i++)
    {
        g->adjList[i] = NULL;
        g->visited[i] = 0;
    }

    return g;

};
void addEdges(struct graph* g,int source,int destination)
{
    //s->d
    struct node* n1=createNode(destination);
    n1->next=g->adjList[source];
    g->adjList[source]=n1;

    //d->s
    struct node* n2=createNode(source);
    n2->next=g->adjList[destination];
    g->adjList[destination]=n2;

}

void print(struct graph* g)
{
    int v;

    for(int v=0; v<g->num_vertices; v++)
    {
        struct node* temp=g->adjList[v];
        printf("\n%d : ",v);
        while(temp)
        {
            printf("%d-> ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }


}


void BFS(struct graph *g,int start)
{

    struct queue *q=createQueue(SIZE);
    g->visited[start]=1;
    enqueue(q,start);
    while(!isQueueEmpty(q))
    {

        int curr = dequeue(q);
        printf("%d ",curr);

        struct node* temp=g->adjList[curr];
        while(temp)
        {
            int adjvertex=temp->data;
            if(g->visited[adjvertex]==0)
            {
                g->visited[adjvertex]=1;
                enqueue(q,adjvertex);

            }
            temp=temp->next;
        }
    }
    q->rear=-1;


}
int main()
{

    struct graph* g=createGraph(5);
    addEdges(g,0,1);
    addEdges(g,0,2);
    addEdges(g,0,3);

    addEdges(g,1,4);

    addEdges(g,2,4);

    addEdges(g,3,4);


    printf("Adjcency List : ");
    print(g);

    printf("\nBFS Traversal is : ");
    BFS(g,0);



}


