#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *left, *right;
    int val, lbit, rbit;
};

struct Node *insert(struct Node *root, int ip)
{
    struct Node *ptr = root;
    struct Node *par = NULL; 
    while (ptr != NULL)
    {
        if (ip == (ptr->val))
        {
            printf("Repeat Key !");
            return root;
        }
        par = ptr; 
        if (ip < ptr->val)
        {
            if (ptr -> lbit == 0)
                ptr = ptr -> left;
            else
                break;
        }
        else
        {
            if (ptr->rbit == 0)
                ptr = ptr -> right;
            else
                break;
        }
    }

    struct Node *temp = malloc(sizeof(struct Node));
    temp -> val = ip;
    temp -> lbit = 1;
    temp -> rbit = 1;

    if (par == NULL)
    {
        root = temp;
        temp -> left = NULL;
        temp -> right = NULL;
    }
    else if (ip < (par -> val))
    {
        temp -> left = par -> left;
        temp -> right = par;
        par -> lbit = 0;
        par -> left = temp;
    }
    else
    {
        temp -> left = par;
        temp -> right = par -> right;
        par -> rbit = 0;
        par -> right = temp;
    }

    return root;
}

struct Node *inorderSuccessor(struct Node *ptr)
{
    if (ptr -> rbit == 1)
        return ptr->right;

    ptr = ptr -> right;
    while (ptr -> lbit == 0)
        ptr = ptr -> left;
    return ptr;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        printf("Tree is empty");

    struct Node *ptr = root;
    while (ptr -> lbit == 0)
        ptr = ptr -> left;

    while (ptr != NULL)
    {
        printf("%d ",ptr -> val);
        ptr = inorderSuccessor(ptr);
    }
}

void preorder(struct Node *root) {
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    struct Node *ptr = root;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        if (ptr->lbit == 1) {
            ptr = ptr->left;
        } else if (ptr->rbit == 1) {
            ptr = ptr->right;
        } else {
            while (ptr != NULL && ptr->rbit == 0) {
                ptr = ptr->right;
            }
            if (ptr != NULL) {
                ptr = ptr->right;
            }
        }
    }
}



int main()
{
    struct Node *root = NULL;

        // INORDER TBT DIAGRAM
        
        //      20
        //     /  \
        //    10  30
        //   /  \
        //   5  16
        //     /  \
        //    14  17
        //    /
        //   13

    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 20);
    

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("\n");

    printf("Preorder: ");
    preorder(root);

    return 0;
}