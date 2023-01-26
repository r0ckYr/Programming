#include<stdio.h>


int N;

int** interchange(int arr[N][N], int a);
int main()
{
    //int N;
    scanf("%d", &N);
    int arr[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d", &arr[i][j]);
            //arr[i][j] = 2+i+1+j;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int **arr2 = interchange(arr, N);
    printf("\n\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int** interchange(int ptr[N][N], int N)
{
    int temp=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
            {
                temp = ptr[i][j];
                ptr[i][j] = ptr[i][N-j-1];
                ptr[i][N-j-1] = temp;
            }
        }
    }
}
