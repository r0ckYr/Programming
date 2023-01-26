#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    scanf("%[^\n]s", s);
    puts(s);
    int l = strlen(s);
    int c=0, max=0;
    char f;
    for(char ch='a';ch<='z';ch++)
    {
        c=0;
        for(int j=0;j<l;j++)
        {
            if(ch==s[j])
                c++;
        }
        if(c>=max)
        {
            if(c==max)
            {
                if(ch<f)
                    f = ch;
            }
            else
            {
            max = c;
            f = ch;
            }
        }
    }
//puts(s);
    printf("Most Frequent : %c\n", f);
}
