#include <stdio.h>
int main(int argc,char *argv[]){
	int i = 0;
	int c,c_prev;
	char string[100] = {0};
	c_prev=0;
	while((c = getchar()) != EOF){
		if( c == ' ' && c_prev == ' '){
			c_prev=c;
			continue;
		}
		string[i++]=c;
		c_prev=c;
	}
	printf("%s\n",string);
	return 0;
}
