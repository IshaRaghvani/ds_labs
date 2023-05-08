#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 999

int minKey(int v, int key[], int set[]) {
    int min = MAX, index;
    for (int i = 0; i < v; i++) {
        if (set[i] == 0 && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void displayMST(int v, int parent[], int graph[v][v]) {
    int c=0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < v; i++) {
        printf("(%d, %d) , weight:  %d\n", parent[i], i, graph[i][parent[i]]);
        c+=graph[i][parent[i]];
    }
    printf("Total Cost: %d",c);
}

void prim(int v, int graph[v][v]) {
    int parent[v], key[v];
    int set[v];

    for (int i = 0; i < v; i++) {
        key[i] = MAX;
        set[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;
    int cost=0;

    for (int i = 0; i < v - 1; i++) {
        int u = minKey(v, key, set);
        set[u] = 1;

        for (int j = 0; j < v; j++) {
            if (graph[u][j] && set[j] == 0 && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];

            }
        }
    }

    displayMST(v, parent, graph);

}

int main() {
    int v = 5;
    int graph[5][5] = {{0, 1, 2, 2, 0},
                       {1, 0, 0, 0, 4},
                       {2, 0, 0, 0, 5},
                       {2, 0, 0, 0, 3},
                       {0, 4, 5, 3, 0}};
   printf("Matrix: \n");
   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        printf("%d ",graph[i][j]);
    }
    printf("\n");

   }
   printf("\n");

    prim(v, graph);
    return 0;
}
