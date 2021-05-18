#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_LEN 128

static int expands1(char *src, char *dst)
{
    int ch;
    while (*src != '\0')
    {
        if (*src >= 'a' && *src <= 'z')
        {
            ch = *src;
            *dst = *src++;
            if (*src == '-')
            {
                src++;
                for (; *dst != *src;)
                {
                    dst++;
                    ch++;
                    *dst = ch;
                }
            }
        }

        if (*src >= '0' && *src <= '9')
        {
            ch = *src;
            *dst = *src++;
            if (*src == '-')
            {
                src++;
                for (; *dst != *src;)
                {
                    dst++;
                    ch++;
                    *dst = ch;
                }
            }
        }

        *dst++ = *src++;
    }

    *dst = '\0';

    return 0;
}

static int expands(char *src, char *dst)
{
    int ch,i,j;
    
    i=j=ch=0;
    
    while((ch = src[i++]) != '\0'){
        if(src[i] == '-' && src[i+1] >= ch){
            i++;
            while(ch < src[i]){
                dst[j++] = ch++;
            }
        }
        else
        {
            dst[j++] = ch;
        }
    }
    return 0;
}
int main(int argc, char **argv)
{
    char acTestBuf1[] = {"a-z"};
    char acTestBuf2[] = {"a-b-c"};
    char acTestBuf3[] = {"a-z0-9"};
    char acTestBuf4[] = {"-a-z"};

    char str[BUF_LEN] = {0};

    printf("expand testbuf1:%s\n", acTestBuf1);
    expands(acTestBuf1, str);
    printf("After expand is :%s\n", str);

    memset(str, 0, sizeof(str));
    printf("expand testbuf2:%s\n", acTestBuf2);
    expands(acTestBuf2, str);
    printf("After expand is :%s\n", str);

    memset(str, 0, sizeof(str));
    printf("expand testbuf3:%s\n", acTestBuf3);
    expands(acTestBuf3, str);
    printf("After expand is :%s\n", str);

    memset(str, 0, sizeof(str));
    printf("expand testbuf4:%s\n", acTestBuf4);
    expands(acTestBuf4, str);
    printf("After expand is :%s\n", str);

    return 0;
}