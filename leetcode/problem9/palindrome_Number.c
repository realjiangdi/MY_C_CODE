#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x){
	int length = 0;
	char buf[32] = {0};
	int i = 0;

	sprintf(buf,"%d",x);
	length = strlen(buf)-1;
	while(i < length){
		//printf("i=%d l = %d \n",i,length);
	
		if(buf[i] != buf[length])
			return false;
		else
		{
			i++;
			length--;
		}
	}
	

	return true;
}

int main(int argc,char*argv[]){
	int test = 121;
	bool testResults = false;
	
	testResults = isPalindrome(test);
	
	if(testResults == true)
		printf("isPalindrome test Nums :%d is palindrome\n",test);
	else
		printf("isPalindrome test Nums :%d id not palindrome\n",test);
	
	testResults = isPalindrome1(test);
	
	if(testResults == true)
		printf("isPalindrome1 test Nums :%d is palindrome\n",test);
	else
		printf("isPalindrome1 test Nums :%d id not palindrome\n",test);
	return 0;
}