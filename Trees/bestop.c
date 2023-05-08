# include <stdio.h>
# include <string.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
 
struct node* newNode(int data);
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
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

int height(struct node * node) {
  if (node == NULL)
    return 0;
  else {
    int lheight = height(node -> left);
    int rheight = height(node -> right);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}

void CurrentLevel(struct node * root, int level) {
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root -> data);
  else if (level > 1) {
    CurrentLevel(root -> left, level - 1);
    CurrentLevel(root -> right, level - 1);
  }
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


void LevelOrder(struct node * root) {
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
    CurrentLevel(root, i);
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void printLevel(struct node* root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
        
        
    }
}

void printTreeLevels(struct node* root) {
    if (root == NULL) return;
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printf("Level %d: ", i);
        printLevel(root, i);
        printf("\n");
    }
}
// int main() {

//     struct node* root = NULL;
//     root = insert(root, 5);
//     root = insert(root, 3);
//     root = insert(root, 7);
//     root = insert(root, 1);
//     root = insert(root, 4);
//     root = insert(root, 6);
//     root = insert(root, 8);
//     LevelOrder(root);
//     printTreeLevels(root);
//     return 0;
// }
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
            printTreeLevels(root);
            break;

            case 3:
            printf("\nInitial Binary Tree:\n");
            printf("\nLevelWise Display\n");
          printTreeLevels(root);
            printf("\nMirror image of the tree:\n");
            root = mirror_image(root);
            printf("\nLevelWise Display\n");
            printTreeLevels(root);
            
            
            break;

            case 4:
            printf("\nLevelWise Display\n");
            printTreeLevels(root);
            LevelOrder(root);
            break;

            case 5:
            printf("\nHeight of the tree: %d\n", height(root));
            printTreeLevels(root);
            break;

            case 6:
            printf("\nLeaf nodes of the tree: \n");
            printTreeLevels(root);
            break;

            case 7:
            exit(0);
            break;

            default:
            printf("Invalid choice, please enter again.\n");

        }
    }

}

