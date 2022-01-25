
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top==MAX-1){
        printf("Stack overflow");
        return;
    }
    top = top+1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(top==-1){
        printf("Stack Underflow");
        exit(1);
    }
    value = stack_arr[top];
    top = top-1;
    return value;
}

void print_data(){
    int i;
    if(top==-1){
        printf("Stack Underflow");
    }
    for(i=top;i>=0;i--){
        printf("%d \n",stack_arr[i]);
    }
}

int main()
{
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    data = pop();
    print_data();
    return 0;
}
