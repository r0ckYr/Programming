#include<stdio.h>

int main()
{   
    int n=5;
    int key, j=0;
    int arr[] = {6,9,1,4,2};
    for(int i=1;i<n;i++)
    {
        key = arr[i];
        j = i;
        while(j>0 && key<arr[j-1])
        {
            arr[j] = arr[j-1];
            j--;
        for(int i=0;i<n;i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        }
        arr[j] = key;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}
