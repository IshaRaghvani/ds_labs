#include <stdio.h>
#define SIZE 20
#include <string.h>

char stack[SIZE];
int top=-1;

char pop(char stack[]){
    int del;
    if(top==-1){
        printf("Stack empty");
    }
    else{
        del = stack[top];
        top--;
    }
    return del;
}
void push(char stack[],int element){
    
    if(top==SIZE-1){
        printf("Stack is full");
    }
    else{
        stack[++top]=element;
    }
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *string){

    int len=strlen(string);
    for(int i=0;i<len;i++){
        if( string[i]=='('){
            push(stack,'(');
        }
        else if(string[i]==')'){
            if(isEmpty()){
                return 0;
            }
            pop(stack);
        }
    }
        
    if(!isEmpty()){
        return 0;
    }
    return 1;

}
int main(){

    char str[]="(()()";
    int r=parenthesisMatch(str);
    if(r){
        printf("paranthesis match");
    }
    else{
        printf("paranthesis not match");
    }
    return 0;
    
}