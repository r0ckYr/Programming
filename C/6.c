#include<stdio.h>
int main()
{
    char str1[100], str2[100];
    gets(str1);
    gets(str2);
    int f = check(str1, str2);
    if(f==1)
        printf("Strings Are Equal");
    else
        printf("Strings Are Not Equal");
}

int check(char *ptr1, char *ptr2)
{
    int i=0;
    while(*(ptr1+i) != '\0' || *(ptr2+i) != '\0')
    {
        if(*(ptr1+i)!=*(ptr2+i))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
