#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100
static int binsearch(int x, int v[], int n)
{
 
    int low , high, mid;

    low = 0;
    high = n -1;
    mid = 0;

    while(low <= high && x != v[mid]){
        mid = (low + high) /2;
        if(x > v[mid])
            low = mid;
        else
            high = mid;

    }

    if(x == v[mid])
        return mid;

    return -1;
}
int main(int argc, char *argv)
{

    int iaTest[MAX_LEN] = {0};
    int i, iRandNum,iret;

    for (i = 0; i < MAX_LEN; i++)
        iaTest[i] = i;

    iRandNum = 27;

    printf("Get Rand Number is %d\n", iRandNum);

    iret = binsearch(iRandNum,iaTest,MAX_LEN);

    if(iret >= 0){
        printf("Find Rand Number in Array %d\n",iret);
    }
    else{
        printf("Cann't find the target number in our array\n");
    }    

    return 0;
}