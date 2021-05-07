#include <stdio.h>
#include <stdlib.h>
/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/
#define BUF_LEN 64

static int any(char *s1, char *s2)
{

    int i, j, k;

    for (i = j = k = 0; s1[i] != '\0'; i++)
    {
        j = i;
        k = 0;
        while(s1[j] == s2[k] && s2[k] != '\0')
        {
            j++;
            k++;
        }

        if (s2[k] == '\0')
        {
            return i;
        }
    }

    return -1;
}
int main(int argc, char *argv[])
{
    int iret = 0;
    char str1[BUF_LEN] = {0};
    char str2[BUF_LEN] = {0};

    printf("please input str1 \n");
    scanf("%s", str1);

    printf("please input str2 \n");
    scanf("%s", str2);

    printf("get str1 %s \nget str2 %s\n", str1, str2);
    iret = any(str1, str2);
    if (iret == -1)
    {
        printf("s1 contains no characters from s2\n");
    }
    else
    {
        printf("the first location ,which any character from the string s2 occurs ,in a string s1 is %d\n", iret);
    }

    return 0;
}