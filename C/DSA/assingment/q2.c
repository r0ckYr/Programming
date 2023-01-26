#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;


node* insert(node *head, int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->info = val;
    p->next = NULL;

    if(head == NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return head;
}


void display(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}


node* createLists(node *h , node **pHead)
{
    while((h->info) >= 0)
    {
        node *temp = h;
        h = h->next;
        if(*pHead == NULL)
        {
            *pHead = temp;
            (*pHead)->next = NULL;
        }
        else
        {
            node *t = *pHead;
            while(t->next!=NULL)
            {
                t = t->next;
            }
            t->next = temp;
            temp->next = NULL;
        }
    }
    node *head = h;

    while(head->next!=NULL)
    {
        if((head->next->info)>=0)
        {
            node *temp = head->next;
            head->next = head->next->next;
            if(*pHead == NULL)
            {
                *pHead = temp;
            }
            else
            {
                node *t = *pHead;
                while(t->next!=NULL)
                {
                    t = t->next;
                }
                t->next = temp;
                temp->next = NULL;
            }
        }
        else
        {
            head = head->next;
        }
    }
    return h;
}


int main()
{
    node *head = NULL;
    node *pHead = NULL;
    node *nHead = NULL;
    
    int n;
    printf("Enter number of nodes :");
    scanf("%d", &n);
    int val = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &val);
        head = insert(head, val);
    }
    
    nHead = createLists(head, &pHead);
    
    printf("Positive list :");
    display(pHead);
    printf("Negative list :");
    display(nHead);
    printf("\n");
}
