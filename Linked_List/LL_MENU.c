#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* insert_front(struct node* head, int data) {
    struct node* newnode = create(data);
    newnode->next = head;
    return newnode;
}

struct node* insert_end(struct node* head, int data) {
    struct node* newnode = create(data);
    if (head == NULL) {
        return newnode;
    }
    struct node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newnode;
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct node* reverse(struct node* head) {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    struct node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Display the list\n");
        printf("4. Reverse the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_front(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_end(head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                head = reverse(head);
                printf("List reversed.\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
