#include<stdio.h>
#include<malloc.h>
struct node{
    struct node *prev,*next;
    int data;
    
};
void create(int n);
void display();
void deleteBegin();
//void deleteAtn();
void deleteEnd();
struct node *head,*last;

int main(){
    int nodes;
    last=NULL;
    printf("\n Enter total nodes in list");
    scanf("%d",&nodes);
    create(nodes);
    printf("\nLinked list is: ");
    display();
    // deleteBegin();
    // printf("After deletion at beginning: ");
    // display();
    return 0;
    // deleteEnd();
    // printf("After deletion at end: ");
    // display();
    // deleteAtn();
    // printf("After deletion at specified position: ");
    // display();


}
void create(int n){
    struct node *newnode;
    int data,i;
    if(n>=1){

        head=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data of 1st node: ");
        scanf("%d",&data);
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        last=head;
        for(int i=2;i<=n;i++){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter next node: ");
            scanf("%d",&data);
            head->data=data;
            head->prev=last;
            head->next=NULL;
            last->next=newnode;
            last=newnode;



        }



    }

}
void display(){
    struct node *temp;
    int n=1;
    if(head==NULL){
        printf("List is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            n++;
            temp=temp->next;
            
        }
        
    }
            
}
void deleteBegin(){
    struct node *temp;
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);

}
void deleteEnd(){
    struct node *temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next->prev =NULL;
    free(temp);
}