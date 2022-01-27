
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 8
char circ_queue[n][20];
int f=-1,r=-1;
void eq()
{
    if((f==0 && r==n-1)||(f==r+1))
    {        printf("Circular Queue is full\n");    }
    if(f==-1)
    {
        f=0;
        r=0;
    }
    else
    {
        if(r==n-1)
        r=0;
        else
        r+=1;
    }
    printf("Enter the element to be enqueued\n");
    scanf("%s",&circ_queue[r++]);
    circ_queue[r][sizeof(circ_queue[r])-1]='\0';
}
void dq()
{
    if(f==-1)
    {        printf("Queue is empty\n");    }
    printf("Deleted element is: %s\n",circ_queue[f]);
    if(f==r)
    {
        f=-1;
        r=-1;
    }
    else
    {
        if(f==n-1)
        f=0;
        else
        f+=1;
    }
}
void display()
{
    int x;
    printf("Elements in the circular queue right now are: \n");
    for(x=f;x<r;x++)
    {        printf("%s ",circ_queue[x]);    }
    printf("\n");
}
int main()
{
    int x=0;
    printf("This is the list of instruction codes to fill the circular queue of size 4\n");
    printf("1) Push\n2) Pop\n3) Display\n4) Exit\n\n");
    while(5)
    {
        printf("Enter the instruction number from the above set\n");
        scanf("%d",&x);
        if(x==1)
        {            eq();        }
        else if(x==2)
        {                dq();        }
        else if(x==3)
        {            display();        }
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

