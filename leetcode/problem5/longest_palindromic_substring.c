#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s){
	
/* 	char *longestSubString = NULL;
	char *ps = NULL;
	char *sc = NULL;
	int longestLength = 0;
	int i,pos,ispal;
	
	pos = ispal = i =0;
	
	if(strlen(s) <= 2){
		longestSubString = (char *)malloc(sizeof(char)+1);
		*longestSubString = *s;
		*(longestSubString+1) = '\0';
		return longestSubString;
	}
	
	while(*s != '\0'){
		ps = s+1;
		pos++;
		ispal = 0;
		if(*ps == '\0')
			break;
	
		for(i=0;i<pos;i++){
			//printf("i=%d,pos = %d\n",i,pos);
			ispal =0;
			if(*(ps-i-1) == *(ps+i+1)){
				//printf("%c \n",*(ps-i-1));
				ispal = 1;
			}
			else
			{
				ispal = 0;
				break;
			}
			
			if(ispal == 1){
				//printf("get sc = %s\n",sc);
				if((2*(i+1) +1) > longestLength){
					sc = ps-i-1;
					longestLength = 2*(i+1) +1;
					//printf("longestLength = %d \n",longestLength);
				}
			}
		}
		
		s++;
	}
	
	if(sc != NULL){
		longestSubString = (char *)malloc(sizeof(char)*longestLength +1);
		ps = longestSubString;
		for(i=0;i<longestLength;i++){
			*longestSubString++ = *sc++;
		}
		*longestSubString = '\0';
		longestSubString = ps;
	}
	
	return longestSubString; */
	
	char *longestSubString = NULL;
	char longestLength = 0;
	int lastindex = 0;
	int i;
	char *p1 = NULL;
	char *p2 = NULL;
	char *p3 = NULL;
	char *p4 =s;
	int same =0;
	if(*s == '\0'){
		return longestSubString;
		
	}
	lastindex = strlen(s);

	
	while(*s != '\0'){
		p2=s+lastindex;
	
		while(s<p2){	
			p1 = s;
			p3 = p2;
			if(*p1 == *p3){
				same =1;
				while(p1<p3){
					if(*p1 != *p3)
					{
						same = 0;
						break;
					}
					p1++;
					p3--;
				}
				
				if(same == 1){
					if((int)(p2 -s)+1 > longestLength){
						longestLength = (int)(p2 -s)+1;
						if(longestSubString != NULL)
							free(longestSubString);
						longestSubString = (char *)malloc(sizeof(char)*longestLength+1);
						
						for(i=0;i<longestLength;i++){
							*(longestSubString+i)=*(s+i);
						}
						*(longestSubString+i) = '\0';
					}
					
				}
			}
			
			p2--;
		}
		s++;
		lastindex--;
	}
	printf("longestLength = %d same = %d\n",longestLength,same);
	if(longestLength == 0 && same == 0){
		longestSubString = (char *)malloc(sizeof(char)+1);
		*longestSubString = *p4;
		*(longestSubString+1) = '\0';
	}
	return longestSubString;
}

int main(int argc,char *argv[]){
	char str[]="babad";
	char *recBuf=NULL;


	printf("Test String is [ %s ]\n",str);
	
	recBuf = longestPalindrome(str);
	
	if(recBuf == NULL){
		printf("there is no palindrome string\n");
	}
	else{
		printf("Get longest Palindrome substring\n");
		printf("%s\n",recBuf);
		
	}
	

	return 0;
}