# include <stdio.h>
# include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
    int height;
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

int height(struct node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}
int getbalance(struct node* root){
    if(root==NULL){
        return 0;
    }
    return (height(root->left)-height(root->right));
}

int max(int a , int b ){
    return(a>b)? a:b;
}

struct node* RightRotate(struct node* root){
    struct node* x= root->left;
    struct node* t= x->right;

    x->right=root;
    root->left=t;
    root->height=1+max(height(root->left),height(root->right));
    x->height=1+max(height(x->left),height(x->right));

    return x;
}

struct node* LeftRotate(struct node* root){
    struct node* x= root->right;
    struct node* t= x->left;

    x->left=root;
    root->right=t;
    root->height=1+max(height(root->left),height(root->right));
    x->height=1+max(height(x->left),height(x->right));

    return x;
}

struct node* insertAVL(struct node* root,int data){
    if(root==NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=data;
        root->right=root->left=NULL;
        root->height=1;
        return root;

    }
    if(data<root->data){
        root->left=insertAVL(root->left,data);
    }
    else if(data>root->data){
        root->right=insertAVL(root->right,data);
    }
    else{
        return root;
    }
    root->height =1+max(height(root->left),height(root->right));
    int balance = getbalance(root);

    //Case: 1 LL
    if(balance>1 && data<root->left->data){
        return(RightRotate(root));
    }
    //Case: 2 RR
    if(balance<-1 && data>root->right->data){
        return(LeftRotate(root));
    }
    //Case: 3 LR
    if(balance>1 && data>root->left->data){
        root->left=LeftRotate(root->left);
        return(RightRotate(root));
    }
    //Case: 4 RL
    if(balance<-1 && data<root->right->data){
        root->right=RightRotate(root->right);
        return(LeftRotate(root));
    }
    return root;
}
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){

    struct node *root = NULL;
 
  
    root = insertAVL(root, 10);
    root = insertAVL(root, 20);
    root = insertAVL(root, 30);
    root = insertAVL(root, 40);
    root = insertAVL(root, 50);
    root = insertAVL(root, 25);
    root = insertAVL(root, 35);

    /* 
            30
           /  \
         20    40
        /  \   / \
       10  25  35  50
  */

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    printf("\nInorder traversal of the constructed AVL tree is \n");
    inorder(root);

    printf("\nLevel Wise  traversal of the constructed AVL tree is \n");
   levelOrderTraversal(root);
   printTree(root);
    
    return 0;


}