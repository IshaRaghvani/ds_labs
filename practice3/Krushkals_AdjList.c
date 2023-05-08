#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 100

// Edge structure
 struct Edge{
    int src;
    int dest;
    int weight;
} ;

// Graph structure
struct Graph{
    struct Edge edges[MAX_EDGES];
    int numEdges;
    int numVertices;
} ;

// Union-Find structure
struct UnionFind{
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} ;

// Function to initialize the Union-Find structure
void initUnionFind(struct UnionFind *uf, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

// Function to find the parent of a vertex in the Union-Find structure
int findParent(struct UnionFind *uf, int vertex) {
    if (uf->parent[vertex] != vertex) {
        uf->parent[vertex] = findParent(uf, uf->parent[vertex]);
    }
    return uf->parent[vertex];
}

// Function to union two vertices in the Union-Find structure
void unionVertices(struct UnionFind *uf, int vertex1, int vertex2) {
    int parent1 = findParent(uf, vertex1);
    int parent2 = findParent(uf, vertex2);

    if (uf->rank[parent1] < uf->rank[parent2]) {
        uf->parent[parent1] = parent2;
    } else if (uf->rank[parent1] > uf->rank[parent2]) {
        uf->parent[parent2] = parent1;
    } else {
        uf->parent[parent2] = parent1;
        uf->rank[parent1]++;
    }
}

// Comparator function for sorting edges
int cmpEdges(const void *a, const void *b) {
    struct Edge *edge1 = (struct Edge *)a;
    struct Edge *edge2 = (struct Edge *)b;

    return edge1->weight - edge2->weight;
}
void bubbleSort(struct Edge *edges, int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                // Swap edges[j] and edges[j+1]
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

// Function to perform Kruskal's Algorithm on a graph
void kruskal(struct Graph *graph, struct UnionFind *uf) {
    // Initialize the union-find data structure
    initUnionFind(uf, graph->numVertices);

    // Sort edges by weight
    bubbleSort(graph->edges, graph->numEdges);

    int numEdges = 0;
    int i = 0;

    while (numEdges < graph->numVertices - 1 && i < graph->numEdges) {
        struct Edge edge = graph->edges[i];

        // Check if adding the edge creates a cycle
        int parent1 = findParent(uf, edge.src);
        int parent2 = findParent(uf, edge.dest);

        if (parent1 != parent2) {
            unionVertices(uf, edge.src, edge.dest);
            printf("(%d, %d) weight = %d\n", edge.src, edge.dest, edge.weight);
            numEdges++;
        }

        i++;
    }
}


int main() {
    struct Graph *graph = malloc(sizeof(struct Graph));
    struct UnionFind *uf = malloc(sizeof(struct UnionFind));

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &graph->numVertices);

    printf("Enter the number of edges in the graph (up to %d): ", MAX_EDGES);
    scanf("%d", &graph->numEdges);



    printf("Enter the source, destination, and weight for each edge:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    kruskal(graph, uf); // Pass pointers to the graph and union-find structures to the kruskal function

    free(graph->edges);
    free(graph);
    free(uf);

    return 0;
}


