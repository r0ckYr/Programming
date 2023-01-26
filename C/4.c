#include<stdio.h>
int main()
{
    int n,m,f=1;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i<j && arr[i][j]!=0)
            {
                f=0;
                break;
            }
        }
        if(f==0)
            break;
    }
    if(f==1)
        printf("Upper Tringular");
    else
        printf("Not Upper Tringular");
}
