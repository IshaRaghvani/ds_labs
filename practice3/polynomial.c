#include <stdlib.h>
#include <stdio.h>
struct node{
    int degree;
    int coeff;
    struct node* next;

};
struct node* create(int degree,int coeff){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->degree=degree;
    newnode->coeff=coeff;
    newnode->next=NULL;
    return newnode;
}
struct node* insert(struct node* head,int degree,int coeff){

    if(head==NULL){
        head=create(degree,coeff);
        return head;

    }
    struct node* temp=head;
    struct node* temp1=create(degree,coeff);
    while(temp->next){
        temp=temp->next;
    }
    temp->next=temp1;
    return head;

}
struct node* addition(struct node* head1,struct node* head2){

    struct node* result=NULL;
    struct node* p1=head1;
    struct node* p2=head2;
    while(p1!=NULL && p2!=NULL){
        if(p1->degree==p2->degree){
            int sum = p1->coeff+p2->coeff;
            result=insert(result,p1->degree,sum);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->degree>p2->degree){
            result=insert(result,p1->degree,p1->coeff);
            p1=p1->next;
        }
        else{
            result=insert(result,p2->degree,p2->coeff);
            p2=p2->next;
        }
    }
    if(p1!=NULL){
        while(p1){
            result=insert(result,p1->degree,p1->coeff);
            p1=p1->next;
        }
    }
    if(p2!=NULL){
        while(p2){
            result=insert(result,p2->degree,p2->coeff);
            p2=p2->next;
        }
    }
    return result;

}
struct node* sub(struct node* head1,struct node* head2){

    struct node* result=NULL;
    struct node* p1=head1;
    struct node* p2=head2;
    while(p1!=NULL && p2!=NULL){
        if(p1->degree==p2->degree){
            int sum = p1->coeff-p2->coeff;
            result=insert(result,p1->degree,sum);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->degree>p2->degree){
            result=insert(result,p1->degree,p1->coeff);
            p1=p1->next;
        }
        else{
            result=insert(result,p2->degree,p2->coeff);
            p2=p2->next;
        }
    }
    if(p1!=NULL){
        while(p1){
            result=insert(result,p1->degree,p1->coeff);
            p1=p1->next;
        }
    }
    if(p2!=NULL){
        while(p2){
            result=insert(result,p2->degree,p2->coeff);
            p2=p2->next;
        }
    }
    return result;

}
void display(struct node* head){
    struct node* temp=head;
    while(temp){
        if(temp->degree!=0 && temp->coeff>0){
            printf("%dx^%d ",temp->coeff,temp->degree);
        }
        else if(temp->degree!=0 && temp->coeff<0){
            printf("%dx^%d ",-temp->coeff,temp->degree);
        }
        else{
            printf("%d ",temp->coeff);
        }
        temp=temp->next;
        if(temp!=NULL && temp->coeff>0){
            printf("+ ");
        }
        else if(temp != NULL && temp->coeff < 0){
            printf("- ");
        }

    }
    printf("\n");
}
struct node* mult(struct node* head1,struct node* head2){
    struct node* p1=head1;

    struct node* sum=NULL;
    struct node* product=NULL;
    int coefficient=0;
     int degree=0;

    while(p1){
        struct node* term=head2;
        while(term!=NULL){
                coefficient=p1->coeff*term->coeff;
                degree=term->degree;

                if(term->degree==0){
                    degree=p1->degree;
                }
                else if(p1->degree==0){
                    degree=term->degree;
                }
                else{
                    degree=p1->degree+term->degree;
                }
                product=insert(product,degree,coefficient);
                term=term->next;

        }
        sum=addition(product,sum);
        if(p1->next==NULL){
            return sum;
        }
        product = NULL;
        p1=p1->next;
    }
    return product;

}

int main(){

    struct node* head1=NULL;
    struct node* head2=NULL;

    head1=insert(head1,2,3);
    head1=insert(head1,1,4);
    head1=insert(head1,0,1);
    printf("\nPolynomial 1 : ");
    display(head1);


    head2=insert(head2,1,2);
    head2=insert(head2,0,1);


    printf("\nPolynomial 2 : ");
    display(head2);
    struct node* sum=addition(head1,head2);
    printf("\nSum of polynomials: ");
    display(sum);
    struct node* subt=sub(head1,head2);
    printf("\nsubtraction of polynomials: ");
    display(subt);
    struct node* mul=mult(head1,head2);
    printf("\nmultiplication of polynomials: ");
    display(mul);



}
