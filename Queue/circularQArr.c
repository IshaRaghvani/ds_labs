# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#define max 4

int queue[max];
int front=-1;
int rear=-1;

void enqueue(int element){
    if(front==-1 &&rear==-1){
       front=0;
       rear=0;
       queue[rear]=element;
       printf("Element %d is enqueued", element);


    }
    else if((rear+1)%max==front){
        printf("Queue is full");
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=element;
        printf("Element %d is enqueued", element);
    }
}
int dequeue(){
    if(rear==-1 && front==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        printf("\nThe dequeued elemet is %d",queue[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("\nThe dequeued elemet is %d",queue[front]);
        front=(front+1)%max;
    }

}
void display(){
    int i=front;
    
    if(rear==-1 && front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("\nQueue is: ");
        while(i != (rear+1)%max){
            printf("%d ",queue[i]);
            i=(i+1)%max;
        }
    }

}

int main(){


    
    int choice;
    int f=1;
    int element;
    int del;

    printf("\n================== CircularQueue implementation using Array ==================\n");
    while(f){
        printf("\nMenu driven program\n");
        printf("1. Circular Inqueue\n");
        printf("2. Circular Dequeue\n");
        printf("3. Circular Display\n");
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