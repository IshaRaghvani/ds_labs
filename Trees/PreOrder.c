# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#define MAX_SIZE 50

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct stack{
    int size;
    int top;
    struct node* *array;
};

struct stack* createStack(int size){
    struct stack* stackNode =(struct stack*)malloc(sizeof(struct stack));
    stackNode->size=size;
    stackNode->top=-1;
    stackNode->array=(struct node*)malloc(sizeof(struct node));
    return stackNode;
    
}
int isFull(struct stack* stack){
    return stack->top-1==stack->size;
}
int isEmpty(struct stack* stack){
    return stack->top==-1;
}
void push(struct stack* stack,struct node* node){
    if(isFull(stack)) return;  //return if stack is full
       //increment top of stack and push the node
    stack->array[++stack->top]=node;
}
struct node* pop(struct stack* stack){
    if(isEmpty(stack)) return NULL; //return if stack is empty
    
    return stack->array[stack->top--]; //return popped element
}

void preorder(struct node* root){
    struct node *ptr=root;
    if(root==NULL){
        return;
    }
    //create an empty stack
    struct stack* stack=createStack(MAX_SIZE);
    //push root to stack
    push(stack,ptr);
    do{
        //pop the top element
        ptr = pop(stack);
        printf("%d\t",ptr->data); //print root element and checkfor left and right children
        if(ptr->right!=NULL){
            push(stack,ptr->right);
        }
        if(ptr->left!=NULL){
            push(stack,ptr->left);
        }
    }
    while(!isEmpty(stack)); //all this while stack is not empty

    
}
void inorder(struct node *root){
    struct node *current=root;
    struct stack* stack=createStack(MAX_SIZE);
    int flag=0;
    //run till current is null and stack is empty
    while(!flag){
        if(current!=NULL){
            push(stack,current);
            current=current->left; //make  left subtree as new root 
        }
        else{
            if(!isEmpty(stack)){
                current=pop(stack);
                printf("%d\t",current->data);
                current=current->right;
            }
            else
                flag=1;
        }
    }


}
struct node* peek(struct stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}
void postorder(struct node *root){

    if (root == NULL)
        return;

    struct stack* stack = createStack(MAX_SIZE);
    do {
        while (root) {
            if (root->right)
                push(stack, root->right);
            push(stack, root);
            root = root->left;
        }
        root = pop(stack);
        if (root->right && peek(stack) == root->right) {
            pop(stack);
            push(stack, root);
            root = root->right;
        } else
        {
            printf("%d\t", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}
struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    return newNode;

}
struct node *insert(struct node* root,int data){
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
}