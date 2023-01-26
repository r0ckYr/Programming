#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


node* push(node* top)
{
    int val = 0;
    node *p = (node*)malloc(sizeof(node));
    printf("Enter Value :");
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;

    if(top==NULL)
    {
        top = p;
    }
    else
    {
        p->next = top;
        top = p;
    }

    return top;
}

node* pop(node* top)
{
    node *temp = top;
    top = top->next;
    free(temp);

    return top;
}

void display(node* top)
{
    printf("\nOutput : ");
    while(top!=NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}


int main(){
    node *top;
    top = NULL;
    int c = 0;
    do{
        printf("\nMenu:\n");
        printf("1. Enter 1 to insert\n2. Enter 2 to delete\n3. Enter 3 to display\n4. Enter 4 to exit\n");
        printf("\nEnter your choice :");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\ninvalid input\n");
        }
    }while(1);
}
