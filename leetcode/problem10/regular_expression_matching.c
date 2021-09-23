#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char*s, char*p){
	char *prep = p;
	while(*p != '\0'){
		if(*(p+1) == '*'){
			prep = p;
			p++;
		} 
	
		printf("prep =%c  p = %c\n",*prep,*p);
		printf("s = %c\n",*s);
		if(*p == '*' && (*prep == '.'|| *s == *prep)){
			s++;
			if(*s == '\0'){
				if(*(p+1) == '\0' || (*(p+1) == *prep && *(p+2) == '\0'))
					return true;
				else 
					return false;
			}
			
		}
		else if(*p == *s || *p== '.'){	
			s++;
			if(*s == '\0'){
				if(*(p+1) == '\0')
					return true;
				else 
					return false;
			}
			
			p++;
		}
		else{
	
			p++;
		}

	}

	if(*p == '\0' && *s == '\0')
		return true;
	else 
		return false;

	
}

int main(int argc,char *argv[]){
	char acBuf[] = "aaa";
	char acRule[]="ab*a*c*a";
	bool Match = false;
	
	Match = isMatch(acBuf,acRule);
	
	if(Match == true)
		printf("Buf:%s Rule:%s true\n",acBuf,acRule);
	else
		printf("Buf:%s Rule:%s false\n",acBuf,acRule);
	return 0;
}