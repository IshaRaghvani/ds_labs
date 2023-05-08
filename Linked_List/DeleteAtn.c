//insering element in the beginning
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;

};
struct node* head;
void Insert(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;

}
void Delete(int pos){
    struct node* temp=head;
    if(pos==1){
        head=temp->next;
        free(temp);
        return;
    }
    
    for(int i=0;i<pos-2;i++){
        temp=temp->next;

    }
    struct node* p=temp->next;
    temp->next=p->next;
    free(p);


    


}

void Print(){
    struct node* temp=head;
    printf("Linked List after deleting element: ");
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int n,x;
    Insert(3);
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();

    printf("Position to be deleted :");
    scanf("%d",&n);
    Delete(n);
    Print();


    

}