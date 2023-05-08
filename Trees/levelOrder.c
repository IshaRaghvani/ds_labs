# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#define max 6

struct node{
    int data;
    struct node *left;
    struct node *right;

};

struct Queue{
    struct node* data;
    struct Queue *next;
};
struct Queue* front=NULL;
struct Queue* rear =NULL;


void enqueue(struct node* node){
    struct Queue *temp=(struct Queue*)malloc(sizeof(struct Queue));
    temp->data=node;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
struct node* dequeue(){
    if(front ==NULL) return NULL;
    struct Queue* temp=front;
    struct node* node =temp->data;

    if(front == rear){
        front = rear= NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
    return(node);


}

struct node *newNode(int data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}
void levelOrderTraversal(struct node* root){

    if(root==NULL){
        return;
    }
    enqueue(root); //when only root is present in the tree
    while(front!=NULL){
        struct node* curr = dequeue();
        printf("%d ",curr->data);

        if(curr->left !=NULL){
            enqueue(curr->left);

        }
       
        if(curr->right!=NULL){
            enqueue(curr->right);
        }
        

    }
    printf(" \n");


}
void printLevel(struct node* root, int level) {
    if (root == NULL) {
        printf(" ");
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

void printTree(struct node* root) {
    int i;
    for (i = 1; i <= 3; i++) {
        printLevel(root, i);
        printf("\n");
    }
}
int main(){

    struct node *root = newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    printf("Level order traversing of binary tree: ");
    levelOrderTraversal(root);
    printTree(root);
    return 0;

}