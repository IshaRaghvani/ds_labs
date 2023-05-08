#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node with the given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count the number of nodes in the binary search tree
int countNodes(struct node* root) {
    int count = 0;
    if (root == NULL) {
        return count;
    }
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct node* current = stack[top--];
        count++;
        if (current->right) {
            stack[++top] = current->right;
        }
        if (current->left) {
            stack[++top] = current->left;
        }
    }
    return count;
}

// Function to find the height of the binary search tree
int findHeight(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int height = 0;
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct node* current = stack[top--];
        if (current->right) {
            stack[++top] = current->right;
        }
        if (current->left) {
            stack[++top] = current->left;
        }
        if (top + 1 > height) {
            height = top + 1;
        }
    }
    return height;
}
void displayLeafNodes(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct node* curr = stack[top--];
        if (curr->left == NULL && curr->right == NULL) {
            printf("%d ", curr->data);
        }
        if (curr->right != NULL) {
            stack[++top] = curr->right;
        }
        if (curr->left != NULL) {
            stack[++top] = curr->left;
        }
    }
}
int search(struct node *root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return 1; // Key found
        }
        else if (key < root->data) {
            root = root->left; // Search left subtree
        }
        else {
            root = root->right; // Search right subtree
        }
    }
    return 0; // Key not found
}

// Main function
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Number of nodes in the binary search tree: %d\n", countNodes(root));
    printf("Height of the binary search tree: %d\n", findHeight(root));
    printf(" Leaf nodes of the binary search tree: " );
    displayLeafNodes(root);

    int f=search(root,30);
    if(f==0){
        printf("key not found");
    }
    else{
        printf("key found");
    }
    int v=search(root,13);
    if(v==0){
        printf("key not found\n");
    }
    else{
        printf("key found");
    }


    return 0;
}
