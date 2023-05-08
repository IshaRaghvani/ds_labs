
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

int stack1[MAX];
int stack2[MAX];
int top1=-1;
int top2=-1;
void push(int stack[MAX],int element){
    if(top1==MAX-1){
        printf("Stack is full cannot push");
    }
    else{

        stack[++top1]=element;
    }

}
int pop(int stack[MAX]){
    int item;
    if(top1==-1){
        printf("\n Stack is empty cannot be popped");
    }
    else{
        item=stack[top1];
        top1--;
    }
    return item;

}
void enqueue(int element){
    push(stack1,element);
    printf("\nElement is pushed");
}
int dequeue(){
    int del_item;
    int answer,p;

    if(top2==-1){
            while(top1!=-1){
                del_item=pop(stack1);
                push(stack2,del_item);
            }

    }
    answer=pop(stack2);
    printf("\ndequeued element is: %d",answer);
    if(top2==-1){
        while(top1!=-1){

                p=pop(stack2);
                push(stack1,p);


        }

    }
    return answer;







}
int main(){
    int ans,ans1;
    push(stack1,8);
    push(stack1,7);
    push(stack1,6);
    ans=dequeue();
    ans=dequeue();
    ans=dequeue();



}
