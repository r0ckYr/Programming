#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct Graph{
    int visited[N];
    int adj[N][N];
} Graph;


//queue
void printGraph(Graph *graph, int V)
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph->adj[i][j])
                printf("(%d-->%d) ", i, j);
        }
        printf("\n");
    }
}

int DFS(Graph *graph, int u, int V)
{
    printf("%d ", u);
    graph->visited[u] = 1;
    for(int i=0;i<V;i++)
    {
        if(!graph->visited[i] && graph->adj[u][i]==1)
        {
            DFS(graph, i, V);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}


void BFS(Graph *graph, int V, int start)
{
    int visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = 0;
    }
    
    int queue[N];
    int front = 0;
    int rear = 0;

    queue[rear++] = start;

    visited[start] = 1;
    while(front!=rear)
    {
        start = queue[front];
        front++;
        printf("%d ", start);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && graph->adj[start][i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}


int main()
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    int V = 7, E = 7;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            graph->adj[i][j] = 0;
        }
    }

    graph->adj[0][1] = graph->adj[1][0] = 1;
    graph->adj[0][2] = graph->adj[2][0] = 1;
    graph->adj[1][3] = graph->adj[3][1] = 1;
    graph->adj[1][4] = graph->adj[4][1] = 1;
    graph->adj[1][5] = graph->adj[5][1] = 1;
    graph->adj[1][6] = graph->adj[6][1] = 1;
    graph->adj[6][2] = graph->adj[2][6] = 1;
    printGraph(graph, V);
    printf("\n");
    for(int i=0;i<V;i++)
    {
        graph->visited[i] = 0;
    }
    
    for(int i=0;i<V;i++)
    {
        if(!graph->visited[i])
        {
            DFS(graph, i, V);
        }
    }
    printf("\n\n");
    BFS(graph, V, 0);
    printf("\n\n");

}
