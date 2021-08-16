#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	
	double return_val = 0.0;
	int i,n1,n2;
	int *piNums;
	int *prNums;
	n1 = nums1Size;
	n2 = nums2Size;
	
	piNums = (int *)malloc(sizeof(int)*(nums1Size+nums2Size));
	
	prNums = piNums;
	//printf("nums1 = %d nums2 = %d\n",nums1Size,nums2Size);
	for(i=0;i<nums1Size+nums2Size;i++){
		if(n1!= 0 && n2 != 0){
			if(*nums1 > *nums2){
				*piNums++ = *nums2++;
				n2--;
			}
			else{
				*piNums++ = *nums1++;
				n1--;
			}
		}
		else if(n1!= 0){
			*piNums++ = *nums1++;
			n1--;
		}
		else{
			*piNums++ = *nums2++;
			n2--;
		}
		
	}
/* 	for(i =0;i<nums1Size + nums2Size;i++){
		printf("%d ",*(prNums+i));
	}
	printf("\n") */;
	
	if((nums1Size+nums2Size)%2 == 0){
		n1 = (nums1Size + nums2Size)/2-1;
		n2 = (nums1Size + nums2Size)/2;
		//printf("n1(%d) = %d n2(%d) =%d\n",n1,*(prNums+n1),n2,*(prNums+n2));
		return_val = (*(prNums+n1) + *(prNums+n2))/2.0;
	}
	else{
		n1 = (nums1Size + nums2Size)/2;
		return_val = *(prNums + n1);
	}
	
	
	return return_val;
}
int main(int argc,char*argv[]){
	
	
	int aiNums1[] = {1,2};
	int aiNums2[] = {3,4};
	double GetValue = 0.0;

	GetValue = findMedianSortedArrays(aiNums1,sizeof(aiNums1)/4,aiNums2,sizeof(aiNums2)/4);
	
	printf("MedianSorted Nums = %.4f",GetValue);
	
	return 0;
}