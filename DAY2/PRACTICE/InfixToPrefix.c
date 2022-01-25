
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
int top=-1;
char stack[max];
int in_pre_fix(char infix[30],char prefix[30]);
void push(char element);
char pop();
void reverse(char rev[30]);
int priority(char element);
int Operator(char element);
int main()
{
    char infix[30],prefix[30];
    printf("Enter the infix expression below\n");
    gets(infix);
    in_pre_fix(infix,prefix);
    reverse(prefix);
    puts((prefix));
    return 0;
}
int in_pre_fix(char infix[30],char prefix[30])
{
    int x,y=0;
    char a;
    stack[top++]='#';
    reverse(infix);
    printf("Prefix expression is: ");
    for(x=0;x<=strlen(infix)-1;x++)
    {
        a=infix[x];
        if(Operator(a)==1)
        {
            prefix[y]=a;
            y++;
        }
        else
        {
            if(a==')')
            {
                prefix[y]=a;
                y++;
            }
            else if(a=='(')
            {
                while(stack[top]!=')')
                {
                    prefix[y]=pop();
                    y++;
                }
                pop();
            }
            else
            {
                if(priority(stack[top])<priority(a))
                {
                    push(a);
                }
                else
                {
                    while((priority(stack[top])>priority(a)))
                    {
                        prefix[y]=pop();
                        y++;
                    }
                    push(a);
                }
            }
        }
    }
    	while (stack[top]!='#')
    	{
		    prefix[y]=pop();
		    y++;
	    }
	    prefix[y]='\0';
}
void reverse(char rev[30])
{
    int x,y;
    char temp[30];
    for(x=strlen(rev)-1,y=0;x>=0;x--,y++)
    {
        temp[y]=rev[x];
    }
    strcpy(rev,temp);
    return temp;
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
int priority(char element)
{
    int z;
    if(element=='+'||element=='-')
    z=1;
    else if(element=='*'||element=='/')
    z=2;
    else if(element=='$'||element=='&')
    z=3;
    else if(element=='#'||element=='('||element==')')
    z=4;
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


