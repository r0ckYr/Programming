#include<stdio.h>
float findMedian(int *arr, int l);

int main()
{
    int T,N,M;
    scanf("%d", &T);
    scanf("%d %d", &N, &M);
    int regions[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d", &regions[i]);
    }
    printf("%f", findMedian(regions, N));
    
}

float findMedian(int *arr, int l)
{
    float median;
    int center  = l/2;
    if(l%2==0)
    {
        median = (arr[center]+arr[center-1])/2.0;
    }
    else
    {
        median = arr[center];
    }
    
    return median;
}
