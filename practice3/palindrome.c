#include <stdio.h>
#include <string.h>


int stack[10];
int top=-1;
void push(int stack[10],int item){

    stack[++top]=item;
}
int pop(int stack[10]){
    return stack[top--];

}
int palindrome(char string[]){
    int mid,i;
    char item;
    int len=strlen(string);
    mid=len/2;
    for(int i=0;i<mid;i++){
        push(stack,string[i]);
    }
    if(strlen(string)%2!=0){
        i++;
    }
    while(string[i]!='\0'){
        item=pop(stack);
        if(item!=string[i])

            return 0;
        i++;
    }
    return 1;




}
int main(){
    char str[]= "abba";
    if(palindrome(str)){
        printf("palindrom");
    }

    return 0;

}
