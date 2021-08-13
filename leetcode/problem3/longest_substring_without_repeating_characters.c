#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int lengthOfLongestSubstring(char *s){
	int length = 0;
	int find = 0;
	char *s1 = s+1;
	char *s2 = s;
	
	if(*s == '\0')
		return length;
	while(*s1 != '\0'){
		s2 = s;
		
		while((s1 - s2) > 0){
			
			if(*s1 != *s2)
			{
				find = 0;
				s2++;
				continue;
			}
			else
			{
				find = 1;
				break;
			}
			
		}
		if((int)(s1 -s) > length){
			length = (int)(s1 - s);
		}
		if(find == 1){
			s=s1;
		}
		s1++;
	}
	

	
	return length;
}

int main(int argc, char *argv[]){

	char str1[] = "abcabcbb";
	int length = 0;
	
	length = lengthOfLongestSubstring(str1);
	
	if(length > 0)
		printf("Get longest Substring[%d]\n",length);
	else
		printf("No longest Substring\n");
	
	return 0;
}