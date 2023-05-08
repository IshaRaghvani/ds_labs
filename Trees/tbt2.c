#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int lbit;
    int rbit;
};



struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lbit = 0;
    newNode->rbit = 0;
    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    struct Node *newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
    } else {
        struct Node *current = root;
        while (1) {
            if (data < current->data) {
                if (current->lbit == 0) { //check if it is a threaded node
                    newNode->left = current->left; //create the link from current to new node
                    newNode->right = current;  //liink the cuurent to right 
                    current->left = newNode;
                    current->lbit = 1;
                    break;
                } 
                else {
                    current = current->left;  //if lbit is 1 then keep traversing and then insert when lbit==0
                }
            } 
            else {
                if (current->rbit == 0) {
                    newNode->right = current->right;
                    newNode->left = current;
                    current->right = newNode;
                    current->rbit = 1;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
    return root;
}

struct Node *inorderSuccessor(struct Node *current) {
    if (current->rbit == 0) {
        return current->right;
    } else {
        current = current->right;
        while (current->lbit == 1) {
            current = current->left;
        }
        return current;
    }
}

void inorderTraversal(struct Node *root) {
    struct Node *current = root;
    while (current->lbit == 1) {
        current = current->left;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = inorderSuccessor(current);
    }
    printf("\n");
}
void preorder(struct Node * root){
    struct Node * temp = root;
    while(temp != NULL){
        printf("%d ", temp->data);
        if(temp->lbit == 1){
            temp = temp->left;
        }
        else if(temp->rbit == 1){
            temp = temp->right;
        }
        else{
            while(temp != NULL && temp->rbit == 0){
                temp = temp->right;
            }
            if(temp != NULL){
                temp = temp->right;
            }
        }
    }
    printf("\n");
}



int main() {
    struct Node *root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}