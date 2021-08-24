#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int reverse(int x){
	int iret ,i,sign;
	int length = 0;
	char buf[128] = {0};
	iret = i = 0;
	sprintf(buf,"%d",x);
	char *pbuf = &buf[0];
	int ipre = 0;
	if(*buf == '-'){
		printf("minus\n");
		length = strlen(buf) -1;
		sign = -1;
		pbuf = pbuf+1;
	}
	else{
		length = strlen(buf);
		sign = 1;
	}
	//printf("length = %d \n",length);
	
	for(i=length-1;i>=0;i--){
		
		iret = iret *10 + (int)(*(pbuf+i) - '0');		
	
		if((iret / 10) != ipre){
			return 0;
		}
		
		ipre = iret;
		
	}
	
	if(sign == -1)
		iret *=-1;

	return iret;
}
int main(int argc,char*argv[]){
	int x = 1534236469;
	int ret;
	printf("Problem7:Reverse Integer\n");
	
	ret = reverse(x);
	
	printf("Integer is %d, reverse integer is %d\n",x,ret);
	
	return 0;
}