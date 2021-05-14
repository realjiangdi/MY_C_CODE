#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN 128
int escape(char *s, char *t)
{

    while(*t != '\0'){
        switch (*t)
        {
        case '\n':
            /* code */
            *s++ = '\\';
            *s++ ='n';
            break;
        case '\t':
            *s++ = '\\';
            *s++ ='t';
            break;
        default:
            *s++=*t++;
            break;
        }
    }
    *s = '\0';
    return 0;
}
int main(int argc, char *argv[])
{

    char buf1[BUF_LEN] = "Hello\tWorld\nHello\tJiangDi\nHello\tCProgram\n";
    char buf2[BUF_LEN] = {0};

    printf("Before Convert\n");
    printf("%s",buf1);
    escape(buf2,buf1);

    printf("After Convert:\n");
    printf("%s\n",buf2);

    return 0;
}