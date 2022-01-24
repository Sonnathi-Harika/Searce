#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
void print_data(struct node *head){
    if(head == NULL)
    printf("Linked list is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr!=NULL){
        printf("%d \n", ptr -> data);
        ptr = ptr -> link;
    }
}
int main()
{
    struct node *tmp, *current;
    int i,p,s;
    printf("Enter no. of elements to be inserted:");
    scanf("%d",&p);
    if(p>0&&p<1000){
        printf("Enter data for node 1");
        scanf("%d",&s);
        struct node *head=NULL;
        head = (struct node*)malloc(sizeof(struct node));
        head -> data = s;
        head ->link = NULL;
        tmp = head;
        for(i=2;i<=p;i++){
            struct node *current=malloc(sizeof(struct node));
            printf("Enter data for node %d",i);
            scanf("%d",&s);
            current -> data = s;
            current -> link = NULL;
            tmp -> link = current;
            tmp = tmp -> link;
        }
        print_data(head);
    }
    else{
        printf("Linked list can be formed only for 0-1000 elements.");
    }
}

