#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


node* insert(node* front, node* rear)
{
    int val = 0;
    node *p = (node*)malloc(sizeof(node));
    printf("Enter Value :");
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;

    if(rear==NULL)
    {
        rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;
    }

    return rear;
}

node* delete(node* front)
{
    node *temp = front;
    front = front->next;
    free(temp);
    return front;
}

void display(node* front)
{
    node *temp = front;
    printf("\nOutput : ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    node *front;
    node *rear;
    int c = 0;
    do{
        printf("\nMenu:\n");
        printf("1. Enter 1 to insert\n2. Enter 2 to delete\n3. Enter 3 to display\n4. Enter 4 to exit\n");
        printf("\nEnter your choice :");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                rear = insert(front, rear);
                if(front==NULL)
                    front = rear;
                break;
            case 2:
                front = delete(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\ninvalid input\n");
        }
    }while(1);
}
