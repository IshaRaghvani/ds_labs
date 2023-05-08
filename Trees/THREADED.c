#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int lbit;
    int rbit;
};

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->lbit = 0;
    newnode->rbit = 0;
    return newnode;
}
struct node *insert(struct node *root, int data)
{

    struct node *newnode = create(data);

    if (root == NULL)
    {
        root = newnode;
    }

    else
    {

        struct node *curr = root;
        while (1)
        {
            if (data < curr->data)
            {
                if (curr->lbit == 0)
                {
                    newnode->left = curr->left;
                    newnode->right = curr;
                    curr->left = newnode;
                    curr->lbit = 1;
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->rbit == 0)
                {
                    newnode->right = curr->right;
                    newnode->left = curr;
                    curr->right = newnode;
                    curr->rbit = 1;
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }
    return root;
}

struct node *inorderSuccessor(struct node *root)
{
    if (root->rbit == 0)
    {
        return root->right;
    }
    else
    {
        root = root->right;
        while (root->lbit == 1)
        {
            root = root->left;
        }
        return root;
    }
}
void inorder(struct node *root)
{
    struct node *curr = root;
    
    while (curr->lbit == 1)
    {
        curr = curr->left;
    }
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = inorderSuccessor(curr);
    }
    printf("\n");
}
int main()
{

    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 2);
    inorder(root);
}