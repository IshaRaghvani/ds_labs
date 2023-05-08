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
    g->adj=malloc(vertices*sizeof(struct node));
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

// void DFS(struct graph *g,int vertex){

//     push(vertex);
//     g->visited[vertex]=1;
//     while(!isEmpty()){
//         int currentvertex = peek();
//         pop();

//         printf("Visited %d ",currentvertex);
//         struct node *adjList=g->adj[currentvertex];
//         struct node* temp=adjList;
//         temp=temp->next;

//         if(g->visited[currentvertex]==0){
//             push(currentvertex);
//             g->visited[currentvertex]=1;
            
//         }
        
        
//     }
    
    





// }
void DFS(struct graph *g, int vertex){
    //The visited array should be updated after the current vertex is popped from the stack, not before.
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
    
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
 
}
int main(){

   struct graph *g=createGraph(7);
   addEdge(g,0, 2);
   addEdge(g,1, 3);
   addEdge(g,0, 1);    // S - A
   
   addEdge(g,2, 4);    // S - C
   addEdge(g,1, 3);    // A - D
   addEdge(g,3, 5);    // B - D
   addEdge(g,5, 4);    // C - D
   //addEdge(g,6, 4);

   
   


   printGraph(g);

   DFS(g,3);
   for (int i = 0; i < g->num_vertices; i++) {
        printf("\nVisited [%d] : ",i);
        printf("%d ", g->visited[i]);
        if(g->visited[i]==0){
            printf("\ngraph is not connected");
            return 0;
        }
    }
    printf("\ngraph is connected");
    return 0;

    
   
   return 0;
}