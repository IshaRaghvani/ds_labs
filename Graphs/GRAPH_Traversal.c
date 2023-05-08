# include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
# define MAX 5
struct graph{
    char data;
    int visited;

};
int stack[5];
int top=-1;


struct graph *vertices[MAX];
int adjMatrix[MAX][MAX];
int vertex_count =0;
//QUEUE OPERATIONS
int queue[MAX];
int rear=-1;
int front=0;
int queue_count=0;
void enqueue(int data){
    queue[++rear]=data;
    queue_count++;

}
int dequeue(){
    queue_count--;
    
    return queue[front++];

}
bool isqueueEmpty(){
    return queue_count==0;
}
//STACK OPERATIONS
void push(int data){
    stack[++top]=data;
}
int pop(){
    return stack[top--];
}
int peek(){
    return stack[top];
}
bool isEmpty(){
    return top==-1;
}
void addVertex(char label){
    //add vertex to a verte arrayx
    struct graph* vertex=(struct graph*)malloc(sizeof(struct graph));
    vertex->data=label;
    vertex->visited=0;
    vertices[vertex_count++]=vertex;

}

void addEdge(int start , int end){
    // add edge ie set matrix entry as 1
    adjMatrix[start][end]=1;
    adjMatrix[end][start]=1;
}
void display(int vertex_index){
    printf("%c ",vertices[vertex_index]->data);
}
int getUnvisitedVertex(int vertex_index ){
     for(int i=0;i<vertex_count;i++){
        // if edge is present but is not visited
        if(adjMatrix[vertex_index][i] == 1 && vertices[i]->visited==0){
            return i;   //return that count

        }
     }
     return -1;
}

void DFS(){

    vertices[0]->visited=1; //mark visited of first node as 1
    display(0); //display that vertex
    push(0); //push first node

    while(!isEmpty()){
        int unvisited = getUnvisitedVertex(peek()); // get the unvisited node for the top of stack
        //if no unvisited node is found at top of stack then pop
        if(unvisited == -1){
            pop();
        }
        else{
            vertices[unvisited]->visited=1; //otherwise set the visited of that top node as 1
            display(unvisited);
            push(unvisited); //and push into the stack
        }
    }
    //after stack is empty , reset the visited entires as 0
    for(int i=0;i<vertex_count;i++){
        vertices[i]->visited=0;
    }
}

void BFS(){
    vertices[0]->visited=1; //mark visited of first node as 1
    display(0); //display that vertex
    enqueue(0); //insert in queue first node

    int unvisited;
    while(!isqueueEmpty()){
        int temp_vertex = dequeue();
        //while no adjacent vertex is found ie front =-1
        while((unvisited=getUnvisitedVertex(temp_vertex))!= -1){
            vertices[unvisited]->visited=1; //otherwise set the visited of that top node as 1
            display(unvisited);
            enqueue(unvisited); //insert into the queue
        }
        // update the temp_vertex to the next unvisited vertex
        temp_vertex = queue[front];
    }
    //after queue is empty and search is complete reset the visited flags to 0
    for(int i=0;i<vertex_count;i++){
        vertices[i]->visited=0;
    }
}



int main(){
    struct graph *g;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            adjMatrix[i][j]=0; //set all entries of matrix as 0 initially

        }
    }

   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4
 
   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D


   
        //              S
        // //         / |  \
        // //       /   |    \
        // //     /     |      \
        // //    A      B       C
        // //    \      |       /
        // //      \    |     /
        // //        \  |   /
        //              D


    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Depth First Search: ");
    DFS();
    printf("\nBreadth First Search: ");
    BFS();

    

    return 0;

}
