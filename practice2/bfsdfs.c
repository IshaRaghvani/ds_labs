#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
struct node
{
    int data;
    struct node* next;

};
struct Graph
{
    int num_vertices;
    struct node* *AdjList;
    int *visited;
};
struct node* create(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct Graph* createGraph(int vertices)
{
    struct Graph* g=(struct Graph*)malloc(sizeof(struct Graph));
    g->num_vertices=vertices;
    g->AdjList= malloc(vertices * sizeof(struct node*));
    g->visited=malloc(vertices * sizeof(int*));

    for(int i=0; i<vertices; i++)
    {
        g->AdjList[i]=NULL;
        g->visited[i]=0;
    }

    return g;

}
void addEdges(struct Graph* g,int src,int dest)
{
    struct node* n1=create(dest);
    n1->next=g->AdjList[src];
    g->AdjList[src]=n1;

    struct node* n2=create(src);
    n2->next=g->AdjList[dest];
    g->AdjList[dest]=n2;

}
void printGraph(struct Graph* g)
{
    int v=0;
    for(v=0; v<g->num_vertices; v++)
    {
        struct node* temp=g->AdjList[v];
        printf("\n%d: ",v);

        while(temp)
        {
            printf("%d->",temp->data);
            temp=temp->next;


        }
        printf("\n");

    }



}
struct queue
{
    int front;
    int rear;
    int items[SIZE];
};

struct queue* createQueue(int size)
{
    struct queue* Q=(struct queue*)malloc(sizeof(struct queue));
    Q->front=-1;
    Q->rear=-1;

    return Q;
}

void enqueue(struct queue* q,int data)
{
    if(q->rear==SIZE-1)
    {
        printf("Queue is full");
    }
    else
    {
        if(q->front==-1)
            q->front=0;
        q->rear++;
        q->items[q->rear]=data;
    }
}
int dequeue(struct queue* q)
{
    int del=0;
    if(q->front==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        del=q->items[q->front];
        q->front++;
    }
    return del;

};


int isQueueEmpty(struct queue *q)
{
    if(q->front ==q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void BFS(struct Graph* g,int start)
{
    struct queue* q=createQueue(20);
    g->visited[start]=1;
    enqueue(q,start);
    while(!isQueueEmpty(q))
    {
        int curr=dequeue(q);
        printf("%d ",curr);
        struct node* temp= g->AdjList[curr];
        while(temp)
        {
            int v=temp->data;
            if(g->visited[v]==0)
            {
                g->visited[v]=1;
                enqueue(q,v);
            }
            temp=temp->next;
        }
    }


}

int main()
{


    struct Graph* g=createGraph(5);

    addEdges(g,0,1);
    addEdges(g,0,2);
    addEdges(g,0,3);
    addEdges(g,1,4);
    addEdges(g,3,4);

    printGraph(g);
    BFS(g,0);





}
