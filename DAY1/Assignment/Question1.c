#include <stdio.h>
int main(){
    int i,q,s;
    int p[q];
    printf("Enter no. of elements to be inserted in array:");
    scanf("%d",&q);
    for(i=0;i<q;i++){
        printf("Enter value for element %d",i);
        scanf("%d",&p[i]);
    }
    for(i=0;i<q/2;i++){
        s = p[i];
        p[i] = p[q-i-1];
        p[q-i-1] = s;
    }
    for(i=0;i<q;i++){
        printf("%d\n",p[i]);   
    }
return 0;
}
    

    