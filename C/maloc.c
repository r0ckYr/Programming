#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[5];
    int *ptr;
    //ptr = (int*)malloc(10*4);
    ptr = a;
    for(int i=0;i<5;i++)
    {
        scanf("%d", &ptr[i]);
    }
    for(int i=0;i<5;i++)
    {
        printf("%d", ptr[i]);
    }
}
