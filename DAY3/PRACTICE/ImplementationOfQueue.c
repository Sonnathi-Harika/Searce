
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10
char queue[n][20];
int f=-1,r=-1;
void eq()
{
    if(r==9)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(f==-1&r==-1)
        {
            f++;
            r++;
        }
        printf("Enter the element to be enqueued\n");
        scanf("%s",&queue[r++]);
        queue[r][sizeof(queue[r]) - 1]='\0';
    }
}
void dq()
{
    if(f==-1||f>r)
    {        
        printf("Queue is empty\n");    
    }
    else
    {        printf("Deleted element is: %s\n",queue[f]);
        f+=1;    }
}
void display()
{
    int x;
    printf("Elements in the queue right now are: \n");
    for(x=f;x<r;x++)
    {
        printf("%s ",queue[x]);
    }
    printf("\n");
}
int main()
{
    int x=0;
    printf("This is the list of instruction codes to fill the queue of size 10\n");
    printf("1) Push\n2) Pop\n3) Display\n4) Exit\n\n");
    while(5)
    {
        printf("Enter the instruction number from the above set\n");
        scanf("%d",&x);
        if(x==1)
        {
            eq();
        }
        else if(x==2)
        {    
            dq();
        }
        else if(x==3)
        {
            display();
        }
        else if(x==4)
        {            exit(0);        }
        else
        {
            printf("Enter a valid instruction number by seeing the list from above\n");
        } 
        printf("__________________________________________________________\n");
        printf("__________________________________________________________\n");
    }
    return 0;
}
