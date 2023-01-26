#include<stdio.h>


#include<string.h>


int checkOccurence(char *word, char *str);


int main()
{
    char str[100];
    scanf("%[^\n]s", str);
    char word[100];
    char mostFrequent[100];
    int k = 0;
    int count=0, max=0;
    strcat(str, " ");
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            word[k] = '\0';
            count = checkOccurence(word, str);
            if(count > max)
            {
                max = count;
                strcpy(mostFrequent, word);          
                k = 0;
            }
        }
        else
        {
            word[k] = str[i];
            k++;
        }
    }
    printf("Most Frequent Word %d: %s\n",max, mostFrequent);
}

int checkOccurence(char *word, char *str)
{   
    char nword[100];
    int k = 0,count=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            nword[k] = '\0';
            if(strcmp(word, nword)==0)
                count++;
            k=0;
        }
        else
        {
            nword[k] = str[i];
            k++;
        }
    }
    return count;
}
