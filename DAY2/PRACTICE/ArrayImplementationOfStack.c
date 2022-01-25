
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else
    return 0;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else
    return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack overflow");
        return;
    }
    top = top+1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    value = stack_arr[top];
    top = top-1;
    return value;
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    return stack_arr[top];
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
    int choice, data;
    while(1){
        printf("\n");
        printf("1~Push the element\n");
        printf("2~Pop the element\n");
        printf("3~Print top element\n");
        printf("4~Print all elements of stack\n");
        printf("5~Quit\n");
        printf("Please enter your choice:\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            printf("Enter value to be pushed:\n");
            scanf("%d",&data);
            push(data);
            break;
            
            case 2:
            data = pop();
            printf("Deleted element is %d", data);
            break;
            
            case 3:
            printf("The topmost element is:%d",peek());
            break;
            
            case 4:
            print_data();
            break;
            
            case 5:
            exit(1);
            
            default:
            printf("Wrong choice");
        }
    }
    return 0;
}
