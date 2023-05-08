#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;

void push(int data){
    
    struct node *temp;
    temp= (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        
        head=temp;
        return;
    }

    temp->next=head;
    head=temp;
    
}
void pop(){
    struct node* temp= head->next;
    
    free(head); 
    head=temp;
    

    
}
void display(){
    struct node* temp=head;
    
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main(){
    // struct node *head1;
    push(2);
    push(3);
    push(4);
    display();
    pop();
    display();
}