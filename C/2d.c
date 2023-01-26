#include<stdio.h>
int** change(int*);
void display(int*);

int main()
{
    int arr[3][3] = {{1,2,3},{7,8,9},{4,5,6}};
    display(arr);
    //change(arr);
}

void display(int arr[][])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;i<3;j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n\n");
}
