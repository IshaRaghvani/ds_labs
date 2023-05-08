#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct stack
{
    int top;
    struct node **array;
    int size;
};
struct stack *createStack(int size)
{
    struct stack *newStack = (struct stack *)malloc(sizeof(struct stack));
    newStack->top = -1;
    newStack->size = size;
    newStack->array = (struct node *)malloc(newStack->size * sizeof(struct node));
    return newStack;
};
int isFull(struct stack *stack)
{
    return stack->top == stack->size;
}
int isEmpty(struct stack *stack)
{
    return stack->top == -1;
}
struct node *pop(struct stack *stack)
{
    if (isEmpty(stack))
    {
        return NULL;
    }
    return stack->array[stack->top--];
}

void push(struct stack *stack, struct node *node)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = node;
}

struct node *newnode(int data, struct node *root)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

struct node *insert(struct node *root, int x)
{

    if (root == NULL)
    {
        return newnode(x, root);
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}
void inorder(struct node *root)
{
    struct node *current = root;
    struct stack *stack = createStack(10);
    if (root == NULL)
    {
        return;
    }
    while (current != NULL)//visiting left subtree
    {
        push(stack, current);
        current = current->left;
    }
    while (!isEmpty(stack))
    {
        current = pop(stack); //printing the left
        printf("%d ", current->data);
        current = current->right; //moving to the right
        while (current != NULL)  //push the left nodes in right subtree
        {
            push(stack, current);
            current = current->left;
        }
    }
}

void postorder(struct node *root)
{

    struct node *prev;

    struct stack *stack = createStack(20);
    if (root == NULL)
    {
        return;
    }
    do
    {
        while (root)
        { // check left subtree
            push(stack, root);
            root = root->left;
        }
        while (root == NULL && !isEmpty(stack))
        { // check right subtree if not visited
            root = stack->array[stack->top];
            if (root->right == NULL || root->right == prev)
            {
                printf("%d ", root->data);
                root = pop(stack);
                prev = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    } while (!isEmpty(stack));
}

void preorder(struct node *root)
{
    struct node *current = root;
    struct stack *stack = createStack(20);

    if (current == NULL)
    {
        return;
    }
    push(stack, current);
    while (!isEmpty(stack))
    {
        current = pop(stack);
        printf("%d ", current->data);
        if (current->right != NULL)
        {
            push(stack, current->right);
        }
        if (current->left != NULL)
        {
            push(stack, current->left);
        }
    }
}
int main()
{
    struct node *root;

    root = newnode(10, root);

    
    insert(root, 15);
    insert(root, 20);
    insert(root, 5);
    insert(root, 2);
    insert(root, 7);
    printf("nodes inserted");
    printf("\nInorder: ");
    inorder(root);
    printf("\npreorder: ");
    preorder(root);
    printf("\npostorder: ");
    postorder(root);

    return 0;
}
