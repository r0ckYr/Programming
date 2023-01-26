#include<stdio.h>
int main()
{
    int a=10,b=20;
    swap(&a, &b);
    printf("a : %d\nb : %d\n", &a, &b);
}

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
