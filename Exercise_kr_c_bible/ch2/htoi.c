#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_BUF 32
int main(int argc, char* argv[]){

    char acBuf[LENGTH_BUF] = {0};
    int i,c,length,value;
    printf("please input a hex digits string for test \n");
   for(i = 0; i< LENGTH_BUF -1 && (c = getchar()) != '\n' && c != EOF;i++)
        acBuf[i] = c;
    acBuf[i] = '\0';
    length = i;
    printf("get acBuf is %s\n",acBuf);

    if(acBuf[0] == '0' && acBuf[1] == 'x' || acBuf[1] == 'X'){
        i = 2;
        value = 0;
        while(acBuf[i] != '\0'){
            if(acBuf[i] >= '0' && acBuf[i] <= '9')
                value = value *16 + acBuf[i] -'0';
            else if(acBuf[i] >= 'a' && acBuf[i] <= 'f')
                value = value * 16 + acBuf[i] -'a' +10;
             else if(acBuf[i] >= 'A' && acBuf[i] <= 'F')
                value = value * 16 + acBuf[i] -'A' +10;
            else{
                printf("error input\n");
                return 1;
            }
            i++;
        }
        printf("get value is %d\n",value);
    }
    else{
        printf("error input\n");
    }


    return 0;
}