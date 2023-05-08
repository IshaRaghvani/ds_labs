# include <stdio.h>
# include <string.h>
#include <stdlib.h>

#include <stdio.h>  

struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *front=-1;  
struct node *rear=-1;  
 
void enqueue(int x)  
{  
    struct node *newnode; 
    newnode=(struct node *)malloc(sizeof(struct node));   
    newnode->data=x;  
    newnode->next=0;  
    if(rear==-1)    
    {  
        front=rear=newnode;  
        rear->next=front;  
    }  
    else   
    {  
        rear->next=newnode;  
        rear=newnode;  
        rear->next=front;  
    }  
}  
  

void dequeue()  
{  
    struct node *temp;   
    temp=front;  
    if((front==-1)&&(rear==-1)) 
    {  
        printf("\nQueue is empty");  
    }  
    else if(front==rear)    
    {  
        front=rear=-1;  
        free(temp);  
    }  
    else  
    {  
        front=front->next;  
        rear->next=front;  
        free(temp);  
    }  
}  
  
  
int peek()  
{  
    if((front==-1) &&(rear==-1))  
    {  
        printf("\nQueue is empty");  
    }  
    else  
    {  
        printf("\nThe front element is %d", front->data);  
    }  
}  
  
// function to display all the elements of the queue  
void display()  
{  
    struct node *temp;  
    temp=front;  
    printf("\n The elements in a Queue are : ");  
    if((front==-1) && (rear==-1))  
    {  
        printf("Queue is empty");  
    }  
  
    else   
    {  
        while(temp->next!=front)  
        {  
            printf("%d,", temp->data);  
            temp=temp->next;  
        }  
        printf("%d", temp->data);  
    }  
}  
 



int main(){


    
    int choice;
    int f=1;
    int element;
    int del;

    printf("\n================== Circular Queue implementation using Linked List ==================\n");
    while(f){
        printf("\nMenu driven program\n");
        printf("1. Circular Linked List Inqueue\n");
        printf("2. Circular Linked List Dequeue\n");
        printf("3. Circular Linked List Display\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter element to insert into queue: ");
            scanf("%d",&element);
            
            enqueue(element);
            break;

            case 2:

            dequeue();
            break;

            case 3:
            display();
            peek();
            break;

            case 4:
            f=0;
            printf("Thankyou");
            break;

            default:
            printf("Invalid choice ");

            


        }    
    }
    
    return 0;

}