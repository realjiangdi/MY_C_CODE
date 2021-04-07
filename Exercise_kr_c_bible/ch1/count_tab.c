#include <stdio.h>
int main(int argc,char *argv[]){

	int nc = 0;
	int c ;
	while((c= getchar()) != EOF)
		if( c == '\t')
		nc++;
	printf("\ncount \\t =  %d\n",nc);
}
