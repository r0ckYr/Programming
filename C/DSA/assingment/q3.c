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


void split(node *head , node **pHead, node **nHead)
{
    int c = 1;
    while(head!=NULL)
    {
        if(c%2==0)
            *pHead = insert(*pHead, head->info);
        else
            *nHead = insert(*nHead, head->info);
        head = head->next;
        c++;
    }
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
    printf("Enter elements :");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &val);
        head = insert(head, val);
    }
    
    split(head, &pHead, &nHead);
    
    printf("Original list :");
    display(head);
    printf("Even list :");
    display(pHead);
    printf("Odd list :");
    display(nHead);
    printf("\n");
}
