
#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node* left;
    struct node* right;

};
struct queue{
    struct node* data;
    struct queue* next;

};
struct queue* front =NULL;
struct  queue* rear =NULL;

void enqueue(struct node* node){
    struct queue* temp =(struct queue*)malloc(sizeof(struct queue));
    temp->data=node;
    temp->next=NULL;

    if(front == NULL && rear == NULL){
        rear=front=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }

}
struct node* dequeue(){
    if(front ==NULL){
        return NULL;

    }
    struct queue* temp=front;
    struct node* node=temp->data;

    if(front == rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
    return node;
};

struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;

};

void levelOrder(struct node* root){
    if(root==NULL){
        return;
    }
    enqueue(root);
    while(front!=NULL){
        struct node* temp=dequeue();
        printf("%d ", temp->data);
        if(temp->left!=NULL){
            enqueue(temp->left);
        }

        if(temp->right!=NULL){
            enqueue(temp->right);
        }
    }
    printf("\n");

}
struct node* insert(struct node* root,int data){
    if(root==NULL){
        root=create(data);
    }
    else if(data<root->data){
            root->left=insert(root->left,data);

    }
    else{

        root->right=insert(root->right,data);

    }
    return root;

};
int main(){

    struct node* root = NULL;
    root=create(10);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,2);
    root=insert(root,15);
    root=insert(root,20);
    printf("inserted");
    levelOrder(root);



}
