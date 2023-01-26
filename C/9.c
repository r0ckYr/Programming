#include<stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%f", &arr[i]);
    }
    float sd = 0.0;
    sd = find_sd(arr, N);
    printf("Standard Deviation : %f", &sd);
}

float find_sd(int *ptr, int N)
{
    float sum = 0.0, mean = 0.0, SD = 0.0;
    for(int i=0;i<N;i++)
    {
        sum = sum + *(ptr+i);
    }
    mean = sum/N;
    for(int i=0;i<N;i++)
    {
        SD = SD + pow((*ptr+i)-mean, 2);
    }
    return sqrt(SD/N);
}
