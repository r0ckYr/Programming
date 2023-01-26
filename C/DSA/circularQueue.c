#include<stdio.h>
#include<stdlib.h>
#define max 5

int insert(int arr[], int front, int rear)
{
    int val=0;
    if((front==0 && rear==max-1) || rear==front-1)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter Value : ");
        scanf("%d", &val);
        if(rear==max-1)
            rear=0;
        else
            rear = rear+1;

        arr[rear] = val;
    }
    return rear;
}


int delete(int arr[], int front, int rear)
{
    if(front==-1)
        printf("Underflow");
    else
    {
        printf("Deleted Value : %d", arr[front]);
        if(front==max-1 && rear!=max-1)
            front = 0;
        else if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front++;
    }
    return front;
}


void display(int arr[], int front, int rear)
{
    if(front==-1)
    {
        printf("Underflow");
    }
    else
    {
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++)
            {
                printf("%d ", arr[i]);
            }
        }
        else
        {
            for(int i=front;i<max;i++)
            {
                printf("%d ", arr[i]);
            }
            for(int i=0;i<=rear;i++)
            {
                printf("%d ", arr[i]);
            }
        }

    }
}


int main(){
    int front = -1;
    int rear = -1;
    int c = 0;
    int arr[max];
    do{
        printf("\nMenu:\n");
        printf("1. Enter 1 to insert\n2. Enter 2 to delete\n3. Enter 3 to display\n4. Enter 4 to exit\n");
        printf("\nEnter your choice :");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                rear = insert(arr, front, rear);
                if(front==-1)
                    front = 0;
                break;
            case 2:
                front = delete(arr, front, rear);
                break;
            case 3:
                display(arr, front, rear);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\ninvalid input\n");
        }
    }while(1);
}
