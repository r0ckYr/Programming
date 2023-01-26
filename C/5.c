#include<stdio.h>

int main()
{
    char str1[100], str2[100];
    gets(str1);
    gets(str2);
    char str3[100];
    int i=0,j=0,k=0;
    char ch = str1[i];
    while(ch != '\0')
    {
        str3[k] = str1[i];
        i++;
        k++;
        ch = str1[i];
    }
    ch = str2[j];
    while(ch != '\0')
    {
        str3[k] = str2[j];
        j++;
        k++;
        ch = str2[j];
    }
    str3[k] = '\0';
    puts(str3);
    return 0;

}
