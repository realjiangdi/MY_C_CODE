#include <stdio.h>
#define Y_WORD 1
#define N_WORD 0
int main(int argc, char *argv[]){
	int c,flag;

	flag = N_WORD;
	while((c = getchar()) != EOF){
	
	if(c == ' ' || c == '\t' || c == '\n'){
			flag = Y_WORD;
			continue;
	}
	else
	{
		if(flag)
			putchar('\n');
		putchar(c);
		flag=N_WORD;	
	}
	
	}
}
