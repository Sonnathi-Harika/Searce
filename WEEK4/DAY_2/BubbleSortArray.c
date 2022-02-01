
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#define n 10

int sort(int arr[]){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main()
{
    int i;
    int arr[n];
    
    for(i=0;i<n;i++){
        printf("Enter the values to be sorted:\n");
        printf("Value of element %d = ",i+1);
        scanf("%d",&arr[i]);
    }
    arr[n] = sort(arr);
    printf("Ascending order of given elements is:");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

