#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node *prev;
    struct node *next;
} node;


node *insert(node *head)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    printf("\nEnter the value:");
    int val;
    scanf("%d",&val);
    p->info = val;
    p->next = NULL;
    p->prev = NULL;

    if(head==NULL)
    {
        head = p;
    }
    else if(head->next == NULL && ((head->info) >= (p->info)))
    {
        node *t = head;
        head = p;
        head->next = t;
        head->prev = NULL;
        t->prev = head;
        t->next = NULL;
    }
    else
    {
        node *temp = head;
        int f = 0;
        while(temp->next!=NULL)
        {
            if((temp->info)>=(p->info))
            {
                f = 1;
                int t = temp->info;
                temp->info = p->info;
                p->info = t;
                
                p->next = temp->next;
                p->prev = temp;
                temp->next->prev = p;
                temp->next = p;

                break;
            }
            temp = temp->next;
        }
        if(f==0)
        {
            temp->next = p;
            p->prev = temp;
        }
    }
    return head;
}

void display(node* head)
{
    node *temp = head;
    printf("\nOutput : ");

    while(temp!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    node *head;
    head = NULL;
    int c = 0;
    do{
        printf("\nMenu:\n");
        printf("1. Enter 1 to insert\n2. Enter 2 to display\n3. Enter 3 to exit\n");
        printf("\nEnter your choice :");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                head = insert(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\ninvalid input\n");
        }
    }while(1);
}
