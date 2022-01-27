
// Online IDE - Code Editor, Compiler, Interpreter

// To print all unique elements present in an array
#include<stdio.h>
int main()
{
    int x,y,z,w;
    int array[100];
    printf("Enter the array limit");
    scanf("%d",&x);
    printf("Enter those %d numbers\n",x);
    for(y=0;y<x;y++)
    {
        printf("Element -%d\n",y);
        scanf("%d",&array[y]);
    }
    printf("The unique elements present in the array are:");
    for(y=0;y<x;y++)
    {
        z=0;
        for(w=0;w<x;w++)
        {
            if(y!=w)
            {
                if(array[y]==array[w])
                z++;
            }
        }
        if(z==0)
        printf("%d\t",array[y]);
    }
    return 0;
}
