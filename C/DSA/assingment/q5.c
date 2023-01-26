#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int number;
    struct node *next;
} node;

node* addTask(node* head)
{ 
    int time = 0;
    printf("Enter task time :");
    scanf("%d", &time);
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = time;
    newNode->next = NULL;
    newNode->number = -1;
    
    if(head==NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->number = 1;
    }
    else
    {
        node *temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->next = head;
        newNode->number = temp->number+1;
    }
    return head;
}


void calculateTaskTime(node* head, int processorTime, int n)
{
    int currentTime = processorTime;
    node *temp = head;

    temp->data = temp->data - processorTime;
    if(temp->data<=0)
    {
        printf("Task %d done in %d ms\n", temp->number, currentTime);
    }

    while(1)
    {

        if(temp->next->data<=0)
        {
            node* t = temp->next;
            temp->next = temp->next->next;
            free(t);
        }

        currentTime = currentTime + processorTime;

        temp->next->data = temp->next->data - processorTime;
        
        if(temp->next->data<=0)
        {
            node* t = temp->next;
            printf("Task %d done in %d ns.\n", temp->next->number, currentTime);
            temp->next = temp->next->next;
            free(t);
        }
        else
        {
            temp = temp->next;
        }
    }
}


void display(node* head)
{
    node *temp = head;
    while(temp->next!=head)
    {
        printf("%d %d\n", temp->data, temp->number);
        temp = temp->next;
    }
    printf("%d %d\n", temp->data, temp->number);
}


int main(){
    node *head;
    head = NULL;
    int n = 0;
    int pTime = 0;
    
    printf("Enter No. of tasks :");
    scanf("%d", &n);
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        head = addTask(head);
    }
    printf("\n");
    printf("Enter Processor Time :");
    scanf("%d", &pTime);
    printf("\n");
    //display(head);
    calculateTaskTime(head, pTime, n);
    return 0;
}
