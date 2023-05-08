#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;

void create(int data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    
}
void delete(int pos){

    struct node* temp=head;
    if(pos==1){
        head=temp->next;
        head=temp;
        free(temp);
        return;
        

    }
    for(int i=0;i<pos-2;i++){
            temp=temp->next;
        }
    struct node* p=temp->next;
    temp->next =p->next;
    free(p);


}

void insert(){

    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    int data,position,n;
    printf("\nEnter number of elemnts in the list: ");
    scanf("%d",n);
    for(int i=0;i<n;i++){
        printf("\nEnter element to be inserted : ");
        scanf("%d",&data);
        printf("\nEnter position at which %d should be inserted : ",data);
        scanf("%d",&position);
        if (position>n){

            temp->data=data;
            temp->next=NULL;

        }
        else{
            if(position==1){
                temp->next=head;
                head=temp;
            }
            else {
                struct node* p =head;
                for(int i=0;i<position-2;i++){
                    p=p->next;
                }
                temp->next=p->next;
                p->next=temp;
            }

        }

    }
    
    

    
   

}
void reverse(){

    struct node* front;
    struct node* current;
    struct node* prev;
    front=NULL;
    current =head;
    prev=NULL;
    while(current!=NULL){
        front=current->next;
        current->next=prev;
        prev=current;
        current=front;
        

    }
    head=prev;
}
void display(){

    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){

    int choice=0;
    

    // int data,pos;
    // printf("Enter data: ");
    // scanf("%d",&data);
    // printf("enter position: ");
    // scanf("%d",&pos);
    
    insert(2,1);
    insert(3,2);
    insert(4,3);
    
    insert(10,4);
    insert(1,1);
    printf("Linked List is: \n");
    display();
    delete(5);
    printf("\nLinked list after deletion: \n");
    display();
    reverse();
    printf("\nLinked list after reversing is: \n");
    display();
    


    

}