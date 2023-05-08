# include <stdio.h>
# include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;

};
struct node* front=NULL;
struct node* rear=NULL;





void inQueue(int data){
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    if((front==NULL)&&(rear==NULL)){
        front=rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
    printf("Node inserted\n");


}
int delQueue(){
    if(front==NULL){
        printf("No elements are present");
    }
    else{
        struct node *temp=front;
        int del=front->data;
        front=front->next;
        free(temp);
        return(del);
    }
}
void display(){
    struct node *temp;
    if((front==NULL) && (rear==NULL)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue: ");
        temp=front;
        while(temp){
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}

int main(){


    
    int choice;
    int f=1;
    int element;
    int del;

    printf("\n================== Linear Queue implementation using Linked List ==================\n");
    while(f){
        printf("\nMenu driven program\n");
        printf("1. LL Inqueue\n");
        printf("2. LL Dequeue\n");
        printf("3. LL Display\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter element to insert into queue: ");
            scanf("%d",&element);
            
            inQueue(element);
            break;

            case 2:

            del=delQueue();
            printf("Deleted element: %d",del);
            break;

            case 3:
            display();
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