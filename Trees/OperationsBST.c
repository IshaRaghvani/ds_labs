# include <stdio.h>
# include <string.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node *create(int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
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
struct node* find_min(struct node *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->left!=NULL)//node with minimum value will have no left child
    {
        return find_min(root->left);

    }
    return root;

}

struct node* delete(struct node* root , int data){
    //search the item that is to be deleted
    if(root==NULL){
        return NULL;
    }
    if(data>root->data){
        root->right=delete(root->right,data);
    }
    else if(data<root->data){
        root->left=delete(root->left,data);
    }
    else{
        //CASE:1 NO child
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //CASE 2: ONE child
        else if(root->left==NULL || root->right==NULL){
            struct node *temp;
            if(root->left==NULL){
                temp=root->right;
            }
            else{
                temp=root->left;

            }
            free(root);
            return temp;
        }
        else{
            //CASE 3: TWO children
            struct node *temp=find_min(root->right); //find minimum node in right subtree
            //replace min value in root->temp
            root->data=temp->data; 
            //delete the duplicate value from right subtree
            root->right=delete(root->right,temp->data);
        }
        
    }
    return root;
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
        
        CurrentLevel(root,i); //print each level
    }
    printf("\n");

}
void DisplayLeafNodes(struct node *root){
    if(root==NULL){
        return ;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }
    DisplayLeafNodes(root->left);
    DisplayLeafNodes(root->right);
}
struct node* mirror_image(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct node* temp = root->left;
    root->left = mirror_image(root->right);
    root->right = mirror_image(temp);
    return root;
}



int main(){
    
    printf("\n=========Operations in BST==========\n");
    int ch;
    struct node *root=NULL;
    
    int w=1,data;
    printf("Enter you choice: \n1.Create and Insert node \n2.Delete\n3.Mirror Image\n4.LevelWise Display\n5.Height of the tree\n6.Display Leaf Nodes\n7.Exit\n");
    while(w==1){
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            
            printf("\nInsert Node: \n");
            scanf("%d",&data);
            
            root= insert(root,data);
            printf("\nNode was inserted\n");
            break;

            case 2:
            
            printf("\nDelete data: \n");
            scanf("%d",&data);
            root=delete(root,data);
            printf("\nNode was deleted\n");
            printf("\nLevelWise Display\n");
            DisplayLevel(root);
            break;

            case 3:
            printf("\nInitial Binary Tree:\n");
            printf("\nLevelWise Display\n");
            DisplayLevel(root);
            printf("\nMirror image of the tree:\n");
            root = mirror_image(root);
            printf("\nLevelWise Display\n");
            DisplayLevel(root);
            
            
            break;

            case 4:
            printf("\nLevelWise Display\n");
            DisplayLevel(root);
            break;

            case 5:
            printf("\nHeight of the tree: %d\n", Height(root));
            break;

            case 6:
            printf("\nLeaf nodes of the tree: \n");
            DisplayLeafNodes(root);
            break;

            case 7:
            exit(0);
            break;

            default:
            printf("Invalid choice, please enter again.\n");

        }
    }

}
