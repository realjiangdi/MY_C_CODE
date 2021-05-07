#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.
*/

#define BUF_LEN 64

static void squeeze(char *s1, char *s2)
{
    int i, j, k, l;

    for (i = j = k = l = 0; s1[i] != '\0';)
    {
        j = i;
        k = 0;
        while (s1[j] == s2[k] && s2[k] != '\0')
        {
            j++;
            k++;
        }
        if (s2[k] == '\0')
        {
            i = i + (j-i);
        }
        else
        {
            s1[l++] = s1[i++];
        }
    }
    s1[l] = '\0';
    return ;
}
int main(int argc , char *argv[]){
    char str1[BUF_LEN] = {0};
    char str2[BUF_LEN] = {0};

    printf("please input str1 \n");
    scanf("%s", str1);

    printf("please input str2 \n");
    scanf("%s", str2);

    printf("get str1 %s \nget str2 %s\n", str1, str2);
    squeeze(str1, str2);
    printf("after squeeze the str1 is %s\n", str1);
}
