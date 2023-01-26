#include<stdio.h>
char* anal(char*);

int main()
{
    char s[100];
    scanf("%s", s);
    char *s1;
    s1 = anal(s);
    printf("%s", s1);
}

char* anal(char *s)
{
    s[0] = 'R';
    printf("%s", s);
    return s;
}
