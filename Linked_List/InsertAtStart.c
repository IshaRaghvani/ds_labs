//insering element in the beginning
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;

};
struct node* head;
void Insert(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    head=temp;

}   
void Print(){
    struct node* temp=head;
    printf("Linked List after inserting element at beginning is: ");
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int n,x;
    printf("Number of elements to store: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the number [%d]: ",i);
        scanf("%d",&x);
        Insert(x);
        Print();
    }

}