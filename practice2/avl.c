
#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;

};
int stack[20];
int top=-1;
struct node* create(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;
}
int h(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;

}
int balance(struct node* root)
{
    if(root==NULL)
        return 0;
    return(h(root->left)-h(root->right));
}
int max(int a,int b)
{
    return (a>b? a:b);
}

struct node* RightRotate(struct node* root)
{
    struct node* x=root->left;
    struct node* T=x->right;

    x->right=root;
    root->left=T;

    //update height
    x->height=1+max(h(x->left),h(x->right));
    root->height=1+max(h(root->left),h(root->right));

    return x;

};
struct node* LeftRotate(struct node* root)
{
    struct node* x=root->right;
    struct node* T=x->left;

    x->left=root;
    root->right=T;

    //update height
    x->height=1+max(h(x->left),h(x->right));
    root->height=1+max(h(root->left),h(root->right));

    return x;

};

struct node* insertAVL(struct node* root,int data)
{
    if(root==NULL)
    {
        return (create(data));
    }
    if(data<root->data)
    {
        root->left=insertAVL(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = insertAVL(root->right,data);
    }
    else
    {
        return root;
    }

    //update the height
    root->height= 1+ max(h(root->left),h(root->right));
    //update the balance
    int b=balance(root);
    //perform rotations
    if(b>1 && data<root->left->data)
    {
        return (RightRotate(root));
    }
    if(b<-1 && data>root->right->data)
    {
        return (LeftRotate(root));
    }
    if(b>1 && data>root->left->data)
    {
        root->left=LeftRotate(root->left);
        return (RightRotate(root));
    }
    if(b<-1 && data<root->right->data)
    {
        root->right=RightRotate(root->right);
        return (LeftRotate(root));
    }
    return root;





}
int queue[SIZE];
int front=0;
int rear=0;
void enqueue(struct node* node)
{

    if(rear==SIZE-1)
    {
        printf("\n Queue full");
    }
    else
    {
        queue[rear]=(int)node;
        rear=rear+1;
    }


}
struct node* dequeue()
{
    if(front == rear){
        printf("queue empty");
        return NULL;
    }
    struct node* del= (struct node*)queue[front];
    front++;
    return del;
}
void postorder(struct node* root)
{
    printf("\nPost order: ");
    struct node* prev=NULL;
    if(root==NULL)
    {
        return ;
    }
    do
    {
        while(root!=NULL)
        {
            stack[++top]=(int)root;
            root=root->left;
            while(root==NULL && top!=-1)
            {
                struct node* temp=(struct node*)stack[top];
                if(temp->right==NULL || temp->right==prev)
                {
                    printf("%d ",temp->data);
                    prev=temp;
                    top--;
                }
                else
                {
                    root=temp->right;
                    break;
                }
            }
        }

    }
    while(top!=-1);
}


void levelorder(struct node* root)
{

    if(root==NULL)
    {
        return;
    }

    enqueue(root);
    printf("\nLevel 1: ");
    while(front!=rear)
    {

        struct node* curr=dequeue();
        printf("%d ",curr->data);

        if(curr->left!=NULL)
        {
            enqueue(curr->left);
        }
        if(curr->right!=NULL)
        {
            enqueue(curr->right);
        }

    }
    printf("\n ");

}

int main()
{

    struct node* root=NULL;
    root = insertAVL(root, 10);
    root = insertAVL(root, 20);
    root = insertAVL(root, 30);
    root = insertAVL(root, 40);
    root = insertAVL(root, 50);
    root = insertAVL(root, 25);
    root = insertAVL(root, 35);

    levelorder(root);
    printf("\nPost order:");
    postorder(root);


}

