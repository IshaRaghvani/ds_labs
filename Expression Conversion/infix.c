#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infix[20],prefix[20],postfix[20];

void infix_to_prefix();
void infix_to_postfix();

char stack[20];
int top=-1;

void push(int index){
    top++;
    stack[top]=infix[index];
};
char pop(){
    char ch;
    ch=stack[top];
    stack[top]='\0';
    top--;
    return(ch);

};
int precedence(char alpha){
    if(alpha =='+' || alpha =='-'){
        return(1);
    }
    if(alpha =='*' || alpha =='/'){
        return(2);
    }
    return 0;
    

}

int main(){

    printf("\nEnter the infix expression: ");
    scanf("%c",&infix);
    
   
    infix_to_postfix();

    // printf("\nInfix to pre fix conversion: ");
    // infix_to_prefix();

    return 0;


}

void infix_to_postfix(){

    
    int i=0,j=0;
    strrev(infix);
    while(infix[i] != '\0')
    {
        //if a-z store in output postfix string
        if(infix[i]>= 'a' && infix[i]<= 'z')
        {
            postfix[j]=infix[i];
            j++;
            i++;

        }
        else if (infix[i] =='(')
        {
            push(i); //push to top of stack
            i++;
        }
        else if (infix[i] ==')')
        {
            //pop till opening bracket is found again
            while(stack[top]!='('){ 
                postfix[j]=pop();
                j++;
            }
            pop();
            i++;
        }
        else
        {
            //check precedence if operation is encountered
            if(precedence(infix[i]) <= precedence(stack[top]))
            {
                //run this till precedence of top of stack is < than infix
                while(precedence(infix[i]) >= precedence(stack[top]))
                {
                    //pop the operator if precedence of opearator already present in stack is higher 
                    postfix[j]=pop();
                    j++;
                    if(top<0){
                        break;
                    }
                }
                push(i);
                i++;
            }
            else
            {
                push(i);
                i++;
            }
        }
    }
while(top!=-1){
    //if stack still has elements left pop it
    postfix[j]=pop();
    j++;
}

postfix[j]='\0'; //add null character to the last 
printf("\nInfix to post fix conversion: %s ",postfix);

}