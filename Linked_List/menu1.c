#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

void insert(int data, int pos){
    if(head == NULL){
        head = create(data);
        return;
    }
    struct Node* temp = head;
    struct Node* temp2;
    if(pos==0){
        temp2 = create(data);
        temp2->next = head;
        head = temp2;
        return;
    }
    for(int i = 0; i < pos-1; i++){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = create(data);
    temp->next->next = temp2;
}

void delete(int pos){
    if(head == NULL) return;
    struct Node* temp = head;
    struct Node* temp2;
    if(pos==0){
        temp2 = temp->next;
        head = temp2;
        free(temp);
        return;
    }
    for(int i = 0; i < pos-1; i++){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void reverse(){
    struct Node* temp = head;
    struct Node* front = NULL;
    struct Node* prev = NULL;
    
    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    head = prev;
}

int length(){
    int x = 0;
    struct Node* temp = head;
    while(temp != NULL){
        x++;
        temp = temp->next;
    }
    return x;
}

void print(){
    struct Node* temp = head;
    printf("The numbers in the linked list is :\n");
    while(temp != NULL){
        printf("%d %u ", temp->data, temp);
        temp = temp->next;
        printf("\n");
    }
    printf("\n");
}

int main(){
    int flag = 1;
    while(flag){
        int ch;
        printf("1 - Insert\n");
        printf("2 - Delete\n");
        printf("3 - Reverse\n");
        printf("4 - Display\n");
        printf("5 - Quit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        int data, pos, x;
        switch (ch)
        {
        case 1:
            printf("Enter the data and position : ");
            scanf("%d %d", &data, &pos);
            x = length();
            if(x<pos){
                insert(data, x);
            }
            else{
                insert(data, pos);
            }
            break;
        case 2:
            printf("Enter the position : ");    
            scanf("%d", &pos);
            delete(pos);
            break;
        case 3:
            reverse();
            print();
            break;
        case 4:
            print();
            break;
        case 5:
            flag = 0;
            printf("Thanks for using!!");
            break;
        default:
            printf("Enter correct input :/");
            break;
        }
    }
    return 0;
}