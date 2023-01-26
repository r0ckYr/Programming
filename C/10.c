#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    gets(s);
    int len=strlen(s);
    char rev[100] 
    rev = reverse(s, len);
    puts(rev);
}

char[] reverse(char *ptr, int len)
{
    int j=0;
    char rev[len];
    for(int i=len-1;i>0;i--)
    {
        rev[j] = ptr[i];
        j++;
    }
    rev[j] = '\0';
    return rev;
}
