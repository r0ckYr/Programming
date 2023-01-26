#include<stdio.h>

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
            j++;
        }
    }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
 
int main()
{
    int n;
    printf("Enter size of array :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements :");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    rearrange(arr, n);
    printf("Arranger array :");
    printArray(arr, n);
    printf("\n");
    return 0;
}
