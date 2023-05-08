#include<stdio.h>
#include<malloc.h>
struct node{
    struct node *prev,*next;
    int data;
    
};
struct node *head;
void insertion_begin();
void insertion_end();
void insertion_specified();
void display();

int main()
{
    int choice=0;
    while(choice!=4)
    {
        printf("\n-----------------Menu Driven Program-------------\n");
        printf("\nChoose one option from list\n");
        printf("\n1. Insert ata beginning \n2. Insertion at the end\n3.Insertion at a specified position\n4. Exit\n5. Display\n");
        printf("\n Enter a choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertion_begin();
            break;
            case 2:
            insertion_end();
            break;
            case 3:
            insertion_specified();
            break;
            case 4:
            exit(0);
            break;
            case 5:
            display();
            break;
            
            default:
            printf("Enter valid choice ");
        }
    }
}
void insertion_begin()
{
    struct node *ptr;
    int data;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("overload");
    }
    else{
        printf("Insert data: ");
        scanf("%d",&data);
    }
    if(head==NULL){
        ptr->prev=NULL;
        ptr->next=NULL;
        ptr->data=data;
        head=ptr;

    }
    else{
        ptr->data=data;
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        
    }
    printf("node inserted");

}

void insertion_end(){

    struct node *ptr,*temp;
    int data;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Overload");
    }
    else{
        printf("Insert data: ");
        scanf("%d",&data);
        ptr->data=data;
        if(head==NULL)
        {
        ptr->prev=NULL;
        ptr->data=data;
        ptr->next=NULL;
        }
        else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp =temp->next;
        }
        
        ptr->prev=temp;
        temp->next=ptr;
        ptr->next=NULL;
        }
    
    printf("Node Inserted ");

    }
    
}
void insertion_specified()
{

    struct node *ptr,*temp;
    int data,loc,i;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Overload");
    }
    else
    {
        temp=head;
        printf("Enter location: ");
        scanf("%d",&loc);
        for(i=2;i<=loc;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("There are less than %d elements");
                return;

            }
        }

    }
    printf("enter data ");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next=ptr;
    temp->next->prev=ptr;
    printf("Node Inserted ");
    


}
void display()  
{  
    struct node *ptr;  
    printf("\n List is: ");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d ,",ptr->data);  
        ptr=ptr->next;  
    }  
}  
