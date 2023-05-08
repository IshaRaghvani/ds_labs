#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node* next;
};

struct node* create(){
    struct node* temp;
    temp =(struct node*)malloc(sizeof(struct node));
    
    return(temp);
}
struct node* insert(struct node* head, int n){
    int x;
    struct node* p;
    printf("enter value: ");
    scanf("%d",&x);
    head->data = x;
    head->next = NULL;

    p=head;
    for(int i=1;i<n;i++){
        p->next = (struct node*)malloc(sizeof(struct node));
        p=p->next;
        printf("enter value: ");
        scanf("%d",&x);
        p->data=x;
        p->next=NULL;

    }
    return (head);

}
void print(struct node* head){
    struct node* p;
    p=head;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
}
int main(){
    struct node* head;
    int n;
    printf("number of elements to store: ");
    scanf("%d",&n);
    head = create();
    head =insert(head , n);
    print(head);

}
