# include <stdio.h>

#include <stdlib.h>

struct node{
    int data;
    int lbit,rbit;
    struct node *left;
    struct node *right;


};
struct node* dummy;

struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->lbit=newnode->rbit=0;
    newnode->left=newnode->right=NULL;
    return newnode;

}
int Height(struct node * node){
    if(node==NULL){
        return 0;
    }
    else{
        int LHeight = Height(node->left);
        int RHeight= Height(node->right);
        if(LHeight>RHeight){
            return(LHeight+1);
        }
        else{
            return(RHeight+1);
        }
    }
}
void CurrentLevel(struct node* root,int level){
    if(root==NULL){
        return ;
    }
    if(level==1){ //BASE CASE
        printf("%d ",root->data);
        printf("\nlbit: %d\n",root->lbit);
        printf("rbit: %d\n",root->rbit);
    }
    else if(level>1){
        CurrentLevel(root->left,level-1); //decrement to move down the levels of the BST
        
        CurrentLevel(root->right,level-1);

        
    }
    

}
void DisplayLevel(struct node *root){
    int h=Height(root);
    int i;
    for(int i=1;i<=h;i++){
        printf("\nLevel:%d \n",i);
        CurrentLevel(root,i); //print each level
    }
    printf("\n");

}
struct node* insert(struct node* root,int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
   
    else if(root->data>data){
        root->left=insert(root->left,data);
        root->lbit=1;
       
    }
    else{
        root->right=insert(root->right,data);
        
        root->rbit=1;
    }
    


}
void preorder(struct node* root){
    if(root==NULL){
        return;
    }
}

int main(){
    int choice , key;
    char ans='N';
    struct *node,*parent,*temp;
    do
    {
        printf("===============Threaded Binary Tree================\n");
        printf("\n1. Create\n2. Display\n3.Search\n4.Delete\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            root=NULL;
            do{
                
            }
        }
    }


}