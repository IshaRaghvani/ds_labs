//inserting a node at nth position
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void Insert(int data,int position){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(position==1){
        temp->next=head;
        head=temp;
        return;
    }
    else{
        struct node* p=head;
        
        for(int i=0;i<position-2;i++){
            p=p->next;

        }
        temp->next=p->next;
        p->next=temp;


    }
}
void Print(){
    struct node* temp=head;
    while(temp !=NULL){ 
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head;
    // int n;
    // int x;
    // printf("Enter the data: ");
    // scanf("%d",&x);
    // printf("Enter position to insert %d in the list: ",x);
    // scanf("%d",&n);
    Insert(2,1);
    Insert(3,2);
    Insert(4,3);
    Insert(5,1);
    Insert(10,3);
    Print();
    


    head=NULL;


}