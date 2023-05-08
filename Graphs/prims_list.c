#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int vertex;
    int weight;
    struct node* next;
};

struct graph {
    int numVertices;
    struct node** adjList;
};

struct node* createNode(int v, int w) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct graph* createGraph(int vertices) {
    struct graph* g = (struct graph*) malloc(sizeof(struct graph));
    g->numVertices = vertices;
    g->adjList = malloc(vertices * sizeof(struct node));

    for(int i=0; i<vertices; i++){
        g->adjList[i] = NULL;
    }

    return g;
}

void addEdge(struct graph* g, int src, int dest, int weight) {
    struct node* newNode = createNode(dest, weight);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

void printGraph(struct graph* g) {
    for(int i=0; i<g->numVertices; i++) {
        struct node* temp = g->adjList[i];
        printf("Vertex %d: ", i);
        while(temp) {
            printf("(%d, w[%d]) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int minKey(int key[], int set[], int V) {
    int min = 999;
    int index;
    for(int i=0; i<V; i++) {
        if(set[i] == 0 && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void prims(struct graph* g) {
    int key[g->numVertices], set[g->numVertices], parent[g->numVertices];

    for(int i=0; i<g->numVertices; i++) {
        key[i] = 999;
        set[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i=0; i<g->numVertices-1; i++) {
        int u = minKey(key, set, g->numVertices);
        set[u] = 1;

        struct node* temp = g->adjList[u];
        while(temp) {
            int v = temp->vertex;
            int weight = temp->weight;
            if(set[v] == 0 && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            temp = temp->next;
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for(int i=1; i<g->numVertices; i++) {
        printf("(%d, %d) -> w: %d\n", parent[i], i, key[i]);
    }
}

int main() {
    struct graph* g = createGraph(5);
    addEdge(g, 0, 1, 1);
    addEdge(g, 0 ,2,2);
    addEdge(g, 0, 3, 2);
    addEdge(g, 1, 4, 4);
    addEdge(g, 2, 4, 5);
    addEdge(g, 3,4 , 3);
    printGraph(g);
    prims(g);

    return 0;
}
