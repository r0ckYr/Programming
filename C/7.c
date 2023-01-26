#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    gets(str);
    int c = 0;
    for(char ch='A';ch<'z';ch++)
    {
        c = 0;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i] == ch)
                c++;
        }
        printf("%c : %d", ch, c);
    }
}
