#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int myAtoi(char * s){

	int nums = 0;
	int current = 0;
	int signs = 1;
	while(*s == ' ')s++;
	
	if(*s == '-' ){
			signs = -1;
			s++;
	}
	else if(*s == '+' ){
			signs = +1;
			s++;
	}
	else{
		signs = 1;
	}
	
	
	while(*s != '\0'){
		if(*s >= '0' && *s <= '9'){
			current = signs*(int)(*s - '0');
			
			if(nums >= INT_MAX/10 && ((nums - INT_MAX/10) > 4 || current > (INT_MAX%10))){
				return INT_MAX;
			}
			
			if(nums <= INT_MIN/10 && ((nums - INT_MIN/10) < -4 || current < (INT_MIN%10))){
				return INT_MIN;
			}
			
			
			
			nums = nums * 10 +current;
			
			
		}
		else{
			break;
		}
	
		s++;
	}

	
	return nums;
}

int main(int argc,char **argv){
	char test[]="-2147483648";
	//char test[]="-42";
	//char test[]="4193 with words";
	int nums = 0;
	printf("string to integer test\n");

	nums = myAtoi(test);
	
	printf("TestBuf is %s, After Convert to integer is %d\n",test,nums);

	return 0;
}
