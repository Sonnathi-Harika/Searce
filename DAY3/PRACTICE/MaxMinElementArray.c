
// Online IDE - Code Editor, Compiler, Interpreter

// To find the maximum and minimum element in an array
#include<stdio.h>
int main()
{
    int x,y,a,b;
    int maxmin[100];
    printf("Number of values to be considering");
    scanf("%d",&x);
    printf("Enter those %d numbers\n",x);
    for(y=0;y<x;y++)
    {
        printf("Element -%d\n",y);
        scanf("%d",&maxmin[y]);
    }
    a=maxmin[0];
    b=maxmin[0];
    for(y=0;y<x;y++)
    {
        if(maxmin[y]>a)
        {
            a=maxmin[y];
        }
        if(maxmin[y]<b)
        {
            b=maxmin[y];
        }
    }
    printf("Maximum value from the entered values is:%d\n",a);
    printf("Minimum value from the entered values is:%d",b);
    return 0;
}

