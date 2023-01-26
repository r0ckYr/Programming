#include<stdio.h>
#include<string.h>

int main()
{
    char s[10];
    scanf("%[^\n]s", s);
    strlwr(s);
    printf("%s", s);
}
