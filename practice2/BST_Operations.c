#include <stdlib.h>
#include <stdio.h>

struct node{
int data;
struct node* left;
struct node* right;
};

struct node* create(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
};

struct node* insert(struct node* root , int data){

    if(root==NULL){
        root=create(data);
    }
    else if (data < root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }

    return root;

};
void Leafnodes(struct node* root){

    if(root==NULL){
        return ;
    }
    struct node* stack[100];
    int top=-1;
    stack[++top]=root;
    while(top>=0){
        struct node* curr = stack[top--];
        if(curr->right == NULL && curr->left == NULL){
            printf("%d ",curr->data);

        }
        if(curr->right!=NULL){
            stack[++top]=curr->right;
        }
        if(curr->left!=NULL){
            stack[++top]=curr->left;
        }


    }

}
int height(struct node* root){
    struct node* stack[100];
    int top= -1;
    int height=0;
    stack[++top]=root;
    while(top>=0){
        struct node* curr=stack[top--];
        if(curr->left!=NULL){
            stack[++top]=curr->left;
        }
        if(curr->right!=NULL){
            stack[++top]=curr->right;
        }

        if(top+1>height){
            height=top+1;
        }
    }
    return height;
}
int search(struct node* node,int key){

    while(node!=NULL)
        {
        if(key==node->data){

        return 1;
    }
    else if (key<node->data){
        node=node->left;
    }
    else{
        node=node->right;
    }


    }
    return 0;





};
int countnodes(struct node* root){

    struct node* stack[100];
    int count=0;
    int top=-1;
    stack[++top]=root;
    while(top>=0){
        struct node* curr = stack[top--];
        count++;
        if(curr->right!=NULL){
            stack[++top]=curr->right;
        }
        if(curr->left!=NULL){
            stack[++top]=curr->left;
        }
    }
    return count;


}

int main(){

    struct node* root = NULL;
    root = create(30);
    printf("Node created\n");
    root = insert(root,15);
    root = insert(root,45);
    root = insert(root,50);
    printf("nodes inserted\n");
    printf("Leaf nodes are: ");
    Leafnodes(root);
    printf("\nNumber of nodes present: %d\n",countnodes(root));
    printf("\nHeight of the BST is: %d\n",height(root));
    int f=search(root,15);
    if(f==1){
        printf("\nKey found");
    }
    else{
        printf("\n Not found");
    }


    //create ad insert
    //deletion
    //search
    //count no. of nodes
    //Height
    //level order traversing
    //leaf nodes
    //mirror image
    //







}
