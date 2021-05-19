#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 1000

static int mygetline(char line[], int max);
static int strindex(char source[], char pattern[]);
static int strindex_rightmost(char source[], char pattern[]);

char pattern[] = "hello";

int main(int argc, char *argv[])
{
    char line[MAX_LEN] = {0};

    int found = 0;

    while (mygetline(line, MAX_LEN) > 0)
    {
        //if(strindex(line,pattern) >= 0)
        if (strindex_rightmost(line, pattern) >= 0)
        {
            printf("match:%s", line);
            found++;
        }
    }

    return found;
}
static int strindex_rightmost(char source[], char pattern[])
{

    int i, j, k, p_len;

    i = strlen(source);
    p_len = strlen(pattern) - 1;
    while (--i >= 0)
    {
        j = p_len;
        k = i;

        for (; j >= 0 && k >= 0 && pattern[j] == source[k]; j--, k--)
                if( j == 0)
                {
                    return k; 
                }
            ;

        // if ((j + 1) == 0)
        // {
        //     return k + 1;
        // }
    }

    return -1;
}
static int mygetline(char line[], int max)
{

    int c, i;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}
static int strindex(char source[], char pattern[])
{
    int i, j, k;

    for (i = 0; source[i] != '\0'; i++)
    {
        for (j = i, k = 0; pattern[k] != '\0' && source[j] == pattern[k]; j++, k++)
            ;
        if (k > 0 && pattern[k] == '\0')
            return i;
    }

    return -1;
}