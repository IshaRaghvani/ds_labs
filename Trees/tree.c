#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
};

int stack[10];
int top = -1;

void push(struct node* node) {
    stack[++top] = node;
}

struct node* pop() {
    struct node* del = stack[top];
    top--;
    return del;
}

int isEmpty() {
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }
}

struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->next = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if(root == NULL) {
        return create(data);
    } else if(data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct node* root) { //P L R
    
    if(root == NULL) {
        return;
    }

    push(root);
    while(!isEmpty()) {
        root = pop();
        printf("%d ", root->data);

        if(root->right != NULL) {
            push(root->right);
        }
        if(root->left != NULL) {
            push(root->left);
        }
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 20);
    printf("\nPreorder: ");
    preorder(root);
    return 0;
}
