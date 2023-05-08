# include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct graph{
    int num_vertices;
    struct node **adj; //array of linked lists
    int *visited;

};
struct node{
    int data;
    struct node* next;


};
int stack[10];
int top=1;
void push(int data){
    stack[++top]=data;
}
int pop(){
    return stack[top--];

}
bool isEmpty(){
    return top==-1;
}
int peek(){
    return (stack[top]);
}

struct node* create(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;


}
struct graph *createGraph(int vertices){

    struct graph *g = (struct  graph*)malloc(sizeof(struct graph));
    g->num_vertices=vertices;
    g->adj=malloc(vertices*sizeof(struct graph));
    g->visited=malloc(vertices*sizeof(int));

    for(int i=0;i<vertices;i++){
        g->adj[i]=NULL;
        g->visited[i]=0;
    }
    return g;


}

void addEdge(struct graph *g, int s,int d){

    struct node* newNode=create(d);
    newNode->next=g->adj[s];
    g->adj[s]=newNode;

    struct node* newNode2=create(s);
    newNode2->next=g->adj[d];
    g->adj[d]=newNode2;




}

void DFS(struct graph *g,int vertex){

    push(vertex);
    while(!isEmpty()){
        int currentvertex = peek();
        pop();

        if(g->visited[currentvertex]==0){
            printf("Visited %d\n", currentvertex);
            g->visited[currentvertex]=1;
        }

        struct node *adjList = g->adj[currentvertex];
        struct node* temp = adjList;

        while(temp){
            int adjvertex = temp->data;
            if(g->visited[adjvertex]==0){
                push(adjvertex);
            }
            temp=temp->next;
        }
    }
}






// Print the graph
void printGraph(struct graph* g) {
  int v;
  for (v = 0; v < g->num_vertices; v++) {
    struct node* temp = g->adj[v];
    printf("\n Adjacency list of vertex %d : ", v);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
int main(){

   struct graph *g=createGraph(5);
   addEdge(g,0, 1);    // S - A
   addEdge(g,0, 2);    // S - B
   addEdge(g,0, 3);    // S - C
   addEdge(g,1, 4);    // A - D
   addEdge(g,2, 4);    // B - D
   addEdge(g,3, 4);    // C - D

    //                  0
        // //         / |  \
        // //       /   |    \
        // //     /     |      \
        // //    1      2       3
        // //    \      |       /
        // //      \    |     /
        // //        \  |   /
        //              4
   printGraph(g);

   DFS(g,0);
   for (int i = 0; i < g->num_vertices; i++) {
        printf("\nVisited [%d] : ",i);
        printf("%d ", g->visited[i]);
   }
   return 0;
}
