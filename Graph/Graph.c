#include<stdio.h>
#include<stdlib.h>


typedef struct edge{
    int info;
    struct edge *next;
}edge;

typedef struct node{
    struct edge *next;
}node;


void addEdge(node nodes[], int v, int e)
{
    edge *temp_edge = (edge*)malloc(sizeof(edge));
    temp_edge->info = e;
    temp_edge->next = NULL;

    if(nodes[v].next==NULL)
    {
        nodes[v].next = temp_edge;
    }
    else
    {
        edge *temp = nodes[v].next;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = temp_edge;
    }
}

void printGraph(node nodes[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n[%d]", i);
        edge *temp = nodes[i].next;

        while(temp!=NULL)
        {
            printf(" -> %d", temp->info);
            temp = temp->next;
        }
    }
    printf("\n\n");
}


int main()
{
    printf("Enter number of vertexes :");
    int n = 0;
    scanf("%d", &n);
    node nodes[n];
    int c = 0;
    while(1)
    {
        printf("\nMenu\n1.Add edge\n2.Print graph\n3.Exit\n\n");
        printf("Enter your choice :");
        scanf("%d", &c);
        switch (c)
        {
            case 1: 
                int v, e;
                printf("Enter vertex and edge(v e) :");
                scanf("%d", &v);
                scanf("%d", &e);
                if(v>=n || e >= n)
                {
                    printf("\n Invalid input!!\n");
                }
                else
                {
                    addEdge(nodes, v, e);
                }
                break;
            case 2:
                printGraph(nodes, n);
                break;
            case 3:
                printf("\n\n");
                return 0;
            default:
                printf("\nInvalid input\n");
                break;
        }
    }
    return 0;

}
