#include<stdio.h>
void count(int *prt, int n, int k);
void readArray(int *ptr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int k;
    readArray(arr, n);
    scanf("%d", &k);
    count(arr, n, k);
}

void readArray(int *ptr, int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d", (ptr+i));
    }
}

void count(int *prt, int n, int k)
{
    int g, l, e;
    for(int i=0;i<n;i++)
    {
        if(*prt>k)
            g++;
        else if(*prt<k)
            l++;
        else
            e++;
        
    printf("Greater : %d\nEqual : %d\n Less : %d\n", g, e, l);
    }
}
