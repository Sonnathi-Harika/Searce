
// Online IDE - Code Editor, Compiler, Interpreter

// To sort elements of an array in ascending order
#include<stdio.h>
int main()
{
    int x,y,z,a;
    int sort[100];
    printf("Number of values to be considering");
    scanf("%d",&x);
    printf("Enter those %d numbers\n",x);
    for(y=0;y<x;y++)
    {
        printf("Element -%d\n",y);
        scanf("%d",&sort[y]);
    }
    printf("The elements you have entered:\n");
    for(y=0;y<x;y++)
    {
        printf("%d\t",sort[y]);
    }
    for(y=0;y<x;y++)
    {
        for(z=y+1;z<x;z++)
        {
            if(sort[y]>sort[z])
           {
            a=sort[y];
            sort[y]=sort[z];
            sort[z]=a;
           }
        }
    }
    printf("\nThe elements after arranging in ascending order is:\n");
    for(y=0;y<x;y++)
    {
        printf("%d\t",sort[y]);
    }
    return 0;
}

