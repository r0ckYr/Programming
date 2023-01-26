#include<stdio.h>
#include<stdlib.h>
#define N 6

struct Node{
    int info;
    struct Node *next;
};

struct Graph{
    struct Node *head[N];
    int visited[N];
    int parent[N];
};

struct Edges{
    int src;
    int dest;
    int weight;
};

struct Graph* createGraph(struct Edges edges[], int n)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    for(int i=0;i<N;i++)
    {
        graph->head[i] = NULL;
    }

    for(int i=0;i<n;i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->info = dest;
        temp->next = NULL;
        graph->parent[dest] = dest;
        if(graph->head[src]==NULL)
        {
            graph->head[src] = temp;
        }
        else
        {
            struct Node *cur = graph->head[src];
            while(cur->next!=NULL)
            {
                cur = cur->next;
            }
            cur->next  = temp;
        }
    }
    return graph;

}


void printGraph(struct Graph *graph)
{
    for(int i=0;i<N;i++)
    {
        struct Node *temp = graph->head[i];
        while(temp!=NULL)
        {
            printf("(%d-->%d) ", i, temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}


void DFS(struct Graph *graph, int src)
{
    printf("%d ", src);
    graph->visited[src] = 1;
    struct Node *temp = graph->head[src];
    while(temp!=NULL)
    {
        if(!graph->visited[temp->info])
            DFS(graph, temp->info);
        temp = temp->next;
    }
}


void kruskalAlog(struct Graph *graph, struct Edges edges[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(edges[j].weight>edges[j+1].weight)
            {
                struct Edges temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
    int i = 0;
    while(i<N-1)
    {
        if(graph->parent[edges[i].src]!=graph->parent[edges[i].dest])
        {
            printf("(%d-->%d)", edges[i].src, edges[i].dest);
            graph->parent[edges[i].dest] = graph->parent[edges[i].src];
            i++;
        }
    }

}

int main()
{
    struct Graph *graph = NULL;
    struct Edges edges[] = {
        {1,3,2},{3,5,1},{0,1,3},{0,2,2}, {1,4,4}, {4,5,3}, {2,4,5}, {3,4,4}, {2,3,9}, {0,5,6}
    };

    int n = sizeof(edges)/sizeof(edges[0]);

    graph = createGraph(edges, n);
    printGraph(graph);
    //DFS
    for(int i=0;i<N;i++)
    {
        graph->visited[i] = 0;
    }

    for(int i=0;i<N;i++)
    {
        if(!graph->visited[i])
            DFS(graph, i);
    }
    printf("\n");
    kruskalAlog(graph, edges, n);
    printf("\n");
}
