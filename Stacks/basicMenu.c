#include <stdio.h>
#define MAX 4
int stack_arr[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1){
        printf("Stack is full");
        return 1;
    }
    else{
        return 0;
    }

}
int isEmpty(){
    if(top==-1){
        printf("Stack is empty");
        return 1;
    }
    else{
        return 0;
    }

}
void push(int data){

    if(isFull()){
        printf("Overflow");
        return;
    }
    else{
        top=top+1;
        stack_arr[top]=data;
        return;
    }
}
int pop(){
    int value;

    if (isEmpty()){
        printf("Underflow");
        return;
    }
    else{
        value=stack_arr[top];
        top=top-1;
        return value;
    }

}
void print(){

    if(isEmpty()){
        printf("No elements present in stack");
    }
    else{
        printf("Stack elemets are: \n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack_arr[i]);
        }
        printf("\n");
    }

}


int main(){

    int flag=1;
    while(flag){
        int choice;

        printf("\n----------------Menu-----------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display top element\n");
        printf("4. Display all\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        int data,del,topElement;

        switch(choice){

            case 1:
            printf("Enter element to be pushed: ");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            del=pop();
            printf("Deleted element is : %d",del);
            break;

            case 3:

            if(isEmpty()){
                printf("stack is empty");
                exit(1);
            }
            else{
                print();
                topElement=stack_arr[top];
                printf("Top element of the stack is: %d",topElement);
            }
            break;
            case 4:
            print();
            break;
            case 5:
            printf("Thankyou");
            exit(1);
            break;
            default:
            printf("enter valid input");
            break;






        }

    }
    return 0;
}