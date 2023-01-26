#include<stdio.h>
void readArray(int* , int);
void mergArrays(int* , int* , int* , int , int);

int main()
{
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int arr1[n1];
    int arr2[n2];
    int arr3[n1+n2];
    readArray(arr1, n1);
    readArray(arr2, n2);
    printf("Merged Array");
    mergArrays(arr1, arr2, arr3, n1, n2);
    for(int i=0;i<n1+n2;i++)
    {
        printf("%d", arr3[i]);
    }
}

void readArray(int *ptr, int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d", ptr+i);
    }
}

void mergeArrays(int *ptr1, int *ptr2, int *ptr3, int n1, int n2)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(ptr1[i]<ptr2[i])
            ptr3[k++] = ptr1[i++];
        else
            ptr3[k++] = ptr2[j++];
    }
    while(i<n1)
    {
        ptr3[k++] = ptr1[i++]; 
    }
    while(j<n2)
    {
        ptr3[k++] = ptr2[j++];
    }
    for(int i=0;i<k;i++)
    {
        printf("%d", ptr3[i]);
    }
}
