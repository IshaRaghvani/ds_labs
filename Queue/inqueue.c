# include <stdio.h>
# include <string.h>
#include <stdlib.h>

struct queue {
    int size;
    int r;
    int f;
    int* arr;

};
int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int dequeue(struct queue *q){
    int x=-1;
    if(isEmpty(q)){
        printf("No elements present in queue");

    }
    else{
        
        x=q->arr[q->f];
        q->f++;
        

    }
    return(x);
}

void enqueue(struct queue *q,int value){
    if(isFull(q)){
        printf("this queue is full");
    }
    else{
        
        q->arr[q->r]=value;
        q->r++;
    }
}
void displayQueue(struct queue* q){
    if(!isEmpty(q)){
        for(int i=q->f;i<q->r;i++){
            printf("|%d",q->arr[i]);
        }
        
       
    }
    printf("|");
    
}
int main(){
    struct queue q;
    q.size=100;
    q.r=-1;
    q.f=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    int choice;
    int f=1;
    int element;
    int del;

    printf("\n================== Linear Queue implementation using array==================\n");
    while(f){
        printf("\nMenu driven program\n");
        printf("1. Inqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter element to insert into queue: ");
            scanf("%d",&element);
            enqueue(&q,element);
            printf("Element is inserted");
            break;

            case 2:

            del=dequeue(&q);
            printf("Deleted element: %d",del);
            break;

            case 3:
            displayQueue(&q);
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