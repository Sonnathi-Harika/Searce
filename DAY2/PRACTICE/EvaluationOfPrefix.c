
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
int top=-1,k;
char stack[max];
int evaluate_prefix(char prefix[30]);
void push(char element);
char pop();
int Operator(char element);
int main()
{
    char prefix[30];
    printf("Enter the prefix expression below\n");
    gets(prefix);
    evaluate_prefix(prefix);
    return 0;
}
int evaluate_prefix(char prefix[30])
{
    int x;
    char a;
    printf("Output after evaluation is: ");
    for(x=0;x<=strlen(prefix)-1;x++)
    {
        a=prefix[x];
        if(Operator(a)==1)
        {
            push(a);
        }
        else if(Operator(a)==0)
        {
            int m=pop();
            int n=pop();
            int output;
            if(a=='+')
            {
                output=m+n;
            }
            else if(a=='-')
            {
                output=m-n;
            }
            else if(a=='*')
            {
                output=m*n;
            }
            else if(a=='/')
            {
                output=m/n;
            }
            push(output);
        }
    }
    printf("%d",pop());
}
int Operator(char element)
{
	int z;
    if(element=='+'||element=='-'||element=='*'||element=='^'||element=='$'||element=='&'||element==')'||element=='(')
    z=0;
    else
    z=1;
    return z;
}
void push(char element)
{
    top++;
    stack[top]=element;
}
char pop()
{
    char z;
    z=stack[top];
    top--;
    return z;
}
