#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int vertex;
    int weight;
    struct node* next;
};

struct graph
{
    int numvertices;
    struct node** adjlist;
};

struct node* create(int vertex, int weight)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->vertex = vertex;
    newnode->weight = weight;
    newnode->next = NULL;
    return newnode;
}

struct graph* createGraph(int vertices)
{
    struct graph* g = (struct graph*) malloc(sizeof(struct graph));
    g->numvertices = vertices;
    g->adjlist = (struct node**) malloc((vertices+1) * sizeof(struct node*));
    for(int i = 0; i <= vertices; i++)
    {
        g->adjlist[i] = NULL;
    }
    return g;
}

void addEdges(struct graph* g, int src, int dest, int w)
{
    struct node* n1 = create(dest, w);
    n1->next = g->adjlist[src];
    g->adjlist[src] = n1;
    struct node* n2 = create(src, w);
    n2->next = g->adjlist[dest];
    g->adjlist[dest] = n2;
}

int minkey(int visited[], int distance[], int v){
    int min = 999;
    int index = -1;
    for(int i = 0; i < v; i++){
        if(visited[i] == 0 && distance[i] <= min){
            min = distance[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(struct graph* g){
    int visited[g->numvertices];
    int distance[g->numvertices];

    // Initialize distance array
    for(int i=0;i<g->numvertices;i++){
        visited[i]=0;
        distance[i]=999; // use a large number instead of 998
    }

    distance[0]=0;

    // Find shortest path from the source vertex (vertex 0) to all other vertices
    for(int i=0;i<g->numvertices-1;i++){ // iterate (n-1) times where n is the number of vertices
        // Find the vertex with the minimum distance from the source vertex
        int u=minkey(visited,distance,g->numvertices);
        visited[u]=1;

        // Update distance array for adjacent vertices
        struct node* temp=g->adjlist[u];
        while(temp){
            int v=temp->vertex;
            int w=temp->weight;
            if(visited[v]!=1 && distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }
            temp=temp->next;
        }
    }

    // Print the minimum spanning tree
    printf("\nMinimum Spanning Tree:\n");
    for(int i=0;i<g->numvertices;i++){
        printf("Vertex %d: weight=%d\n", i, distance[i]);
    }
}


    void print(struct graph* g)
    {

        for(int i=0; i<g->numvertices; i++)
        {
            struct node* temp=g->adjlist[i];
            printf("\nVertex: %d ",i);
            while(temp)
            {
                printf("(%d w[%d])-> ",temp->vertex,temp->weight);
                temp=temp->next;
            }
            printf("NULL\n");



        }

    }
    int main()
    {

        struct graph* g=createGraph(4);
        printf("ddd");
        addEdges(g,0,1,1);
        addEdges(g,0,2,2);
        addEdges(g,0,3,3);
        addEdges(g,2,3,2);



        printf("jahaj");
        print(g);

        dijkstra(g);


    }
