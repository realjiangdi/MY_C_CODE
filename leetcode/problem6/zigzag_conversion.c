#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
	char *ZagString = NULL;
	int length = strlen(s);
	int index[numRows];
	char acStr[numRows][length];
	int i,j,sign;
	i=j=0;
	sign = 1;
	/* printf("strlength = %d\n",length); */
	memset(index,0,sizeof(index));
	while(*(s+i) != '\0'){
		if(j==0)
			sign = 1;
		if(j==(numRows - 1))
			sign = -1;
		
		/* printf("j=%d\n",j); */
		
		acStr[j][index[j]] = *(s+i);
		index[j]++;
		
		
		
		if(sign == 1)
			j++;
		else
			j--;
		i++;
	}
	for(i=0;i<numRows;i++){
		acStr[i][index[i]]='\0';
		/* printf("index[%d] = %d\n",i,index[i]); */
	}
	
/* 	for(i=0;i<numRows;i++){
		printf("s = %s\n",acStr[i]);
	} */
	ZagString = (char *)malloc(length+1);
	
/* 	strcpy(ZagString,acStr[0]);
	for(i=1;i<numRows;i++){
		strcat(ZagString,acStr[i]);
	} */
	j=0;
	for(i=0;i<numRows;i++){
		memcpy(ZagString+j,acStr[i],index[i]);
		j+=index[i];
	}
	*(ZagString+length) = '\0';
	return ZagString;
}
int main(int argc ,char *argv[]){
	char testStr[]="PAYPALISHIRING";
	int numRows = 3;
	char *ZagStr = NULL;
	
	printf("testStr = %s\n",testStr);
	
	ZagStr = convert(testStr,numRows);
	
	if(ZagStr == NULL){
		printf("STR IS NULL\n");
	}
	else
	{
		printf("After ZigZag conversion is :%s\n",ZagStr);
	}
	
	return 0;
}