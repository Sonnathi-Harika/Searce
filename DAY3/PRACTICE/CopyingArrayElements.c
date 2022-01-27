
// Online IDE - Code Editor, Compiler, Interpreter

// To copy the elements of one array into another array
#include<stdio.h>

int main()
{
    int x,y;
    int array1[50],array2[50];
    printf("Enter the Array limit:");
    scanf("%d",&x);
    printf("Enter the array values\n");
    for(y=0;y<x;y++)
    {
        printf("Array1[%d]",y);
        scanf("%d",&array1[y]);
    }
    for(y=0;y<x;y++)
    {
        array2[y]=array1[y];
    }
    printf("\nElements in the first array are: ");
    for(y=0;y<x;y++)
    {
        printf(" %d\t",array1[y]);
    }
    printf("\nElements copied to the second array are: ");
    for(y=0;y<x;y++)
    {
        printf(" %d\t",array2[y]);
    }
    return 0;
}

