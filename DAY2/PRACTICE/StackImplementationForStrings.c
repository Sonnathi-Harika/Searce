
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10
int top=-1;
char arr[n][n];
char arr1[100];
int push();
int pop();
int display();
int main()
{
   int x;
    printf("This is the list of instruction codes to fill the stack of size 10\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
   while(5)
   {
       printf("Enter the instruction number from the list above\n");
        scanf("%d",&x);
        if(x==1)
             push();
        else if(x==2)
             pop();
        else if(x==3)
             display();
        else if(x==4)
        {
             exit(0);
             printf("End of the program\n");
        }
        printf("\n_____________________________________\n");
   }
   return 0;
}
int push()
{
    if(top>=n)
	{
		printf("Stack is full\n");
	}
	else
	{
	    int i;
	    top+=1;
	    char string[100];
		puts("Enter the element you want to push");
		scanf("%s",&arr1);
		for(i=0;i<strlen(arr1);i++)
        arr[top][i]=arr1[i];
	}
}
int pop()
{
    if(top==-1)
	{
		printf("\nStack is empty\n");
	}
	else
	{
		printf("Deleted alphabet is: %s\n",arr[top]);
		top-=1;
	}
}
int display()
{
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("Alphabets in the stack are:\n");
        int i;
        for(i=0;i<=top;i++)
        {   
            printf(" %s",arr[i]);
        }
    }
}

