#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
#define NUM_SIZE 4
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i,j,sum;
	int *returnNums;
	for(i=0;i<numsSize-1;i++){
		for(j=i+1;j<numsSize;j++){
			sum = nums[i] + nums[j];
			if(sum == target){

				returnNums = (int *)malloc(sizeof(int)*2);
				returnNums[0] = i;
				returnNums[1] = j;
				*returnSize = 2;
				return returnNums;

			}
		}

	}

	*returnSize = 0;
	return NULL;
}
int main(int argn ,char*argv[]){

	printf("leetcode 1 20210811\n");

	int aiNum[NUM_SIZE]={2,7,11,15};
	int itarget = 9;
	int returnSize = 0;
	int *piReturnNums = NULL;


	piReturnNums = twoSum(aiNum,NUM_SIZE,itarget,&returnSize);

	if(returnSize == 0){
		printf("There is no target values\n");
	}
	else{
		printf("return index is %d,%d\n",*piReturnNums,*(piReturnNums + 1));
		free(piReturnNums);
	}


	return 0;
}
