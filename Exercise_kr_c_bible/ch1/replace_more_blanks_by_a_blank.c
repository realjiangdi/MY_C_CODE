#include <stdio.h>
int main(int argc,char *argv[]){
	int nb;
	int i = 0;
	int c;
	char string[100] = {0};
	while((c = getchar()) != EOF){
		if(c == ' ' && nb == 0){
			string[i++]=c;
			nb++;		
		}
		else if( c == ' ' && nb != 0)
			continue;
		else{
			string[i++]=c;
			nb=0;
		}	
	}
	printf("\n%s\n",string);
	return 0;
}
