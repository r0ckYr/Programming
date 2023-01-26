#include <stdio.h>
#include <stdlib.h>
 
#define N 6

struct Graph
{
    struct Node* head[N];
    int visited[N];
    int parent[N];
};
 
struct Node
{
    int dest;
    int weight;
    struct Node* next;
};
 
struct Edge {
    int src, dest, weight;
};
 
struct Graph* createGraph(struct Edge edges[], int n)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }
 
    for (int i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->dest = dest;
        newNode->weight = weight;
        graph->parent[dest] = dest;

        if(graph->head[src]==NULL)
        {
            graph->head[src] = newNode;
        }
        else
        {
            struct Node* temp = graph->head[src];
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
 
    return graph;
}
 
void printGraph(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


void kruskalAlog(struct Graph *graph, struct Edge edges[], int n)
{
    struct Edge t;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if((edges[j].weight) > (edges[j+1].weight))
            {
                t = edges[j];  
                edges[j] = edges[j+1];
                edges[j+1] = t;
            }
        }
    }

    int mincost = 0;
    int i=0;
    while(i<N-1)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        if(graph->parent[src]!=graph->parent[dest])
        {
            printf("(%d -> %d)\n", src, dest);
            graph->parent[dest] = graph->parent[src]; 
            
            graph->visited[src] = 1;
            graph->visited[dest] = 1;

            mincost = mincost + weight;
            i++;
        }
    }
    printf("\nMinimum Cost = %d\n", mincost);
}


int main(void)
{
    struct Edge edges[] =
    {
        {1, 3, 2}, {3, 5, 1}, {0, 1, 3}, {0, 2, 2}, {1, 4, 4}, {4, 5, 3}, {2, 4, 5}, {3, 4, 4}, {2, 3, 9}, {0, 5, 6}
    };
 
    int n = sizeof(edges)/sizeof(edges[0]);
 
    struct Graph *graph = createGraph(edges, n);
 
    printGraph(graph);
        
    for(int i=0;i<N;i++)
    {
        graph->visited[i] = 0;
    }

    kruskalAlog(graph, edges, n);
    
    return 0;
}
