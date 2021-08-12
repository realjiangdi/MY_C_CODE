#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
enum{
	RETURN_OK ,
	RETURN_ERROR,
};

typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode_T;

int deleteList(struct ListNode* pHeadNode){
	
	struct ListNode* pNextNode;
	struct ListNode* pListNode;
	int count = 0;
	if(pHeadNode == NULL)
	{
		printf("This list is NULL\n");
		return RETURN_ERROR;
	}
	pListNode = pHeadNode;
	
	while(pListNode!= NULL){
		pNextNode = pListNode->next;
		free(pListNode);
		pListNode = pNextNode;
		count ++;
	}
	
	printf("delete %d ListNodes\n",count);
	
	return RETURN_OK;
}
struct ListNode* createList(int size,int array[]){
	
	struct ListNode* pHeadNode = NULL;
	struct ListNode* pListNode= NULL;
	struct ListNode* pPreNode = NULL;
	int i = 0;

	for(i = 0;i<size;i++){
		
		pListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		
		if(pListNode == NULL)
		{
			printf("%d listNode malloc failed\n",i);
			deleteList(pHeadNode);
			return NULL;
		}
		pListNode->val = array[i];
		pListNode->next = NULL;
		/* printf("create index%d =%d\n",i,array[i]); */
		
		if(pHeadNode==NULL)
			pHeadNode = pListNode;
		if(pPreNode == NULL)
			pPreNode = pListNode;
		else{
			pPreNode->next = pListNode;
			pPreNode = pListNode;
		}
			
			
	}
	
	
	
	return pHeadNode;
}
int traverseList(struct ListNode* pHeadNode){
	
	struct ListNode* pListNode = NULL;
	int count = 0;
	
	pListNode = pHeadNode;
	
	printf("traverseList: ");
	while(pListNode != NULL){
		printf("%d ",pListNode->val);
		pListNode=pListNode->next;
		count++;
	}
	printf("\n");
	
	return count;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int carry,remainder,sums;
	int val1 , val2 ;
	struct ListNode* pListNode = NULL;
	struct ListNode* pHeadNode = NULL;
	struct ListNode* pPreNode = NULL;
	
	val1 = val2 = carry = 0;
	while(l1!=NULL || l2!=NULL || carry != 0){
	
	if(l1!= NULL){
		val1 = l1->val;
		l1=l1->next;
	}
	else{
		val1 = 0;
	}
	if(l2!= NULL){
		val2 = l2->val;
		l2 = l2->next;
	}
	else{
		val2 = 0;
	}
		sums = val1 + val2 + carry;
		remainder = sums%10;
		carry = sums/10;
		
		
		pListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		if(pListNode == NULL){
			deleteList(pHeadNode);
			return NULL;
		}
		
		pListNode->val = remainder;
		
		if(pPreNode == NULL){
			pPreNode = pListNode;
		}
		else{
			pPreNode->next = pListNode;
			pPreNode = pListNode;
		}
		
		if(pHeadNode == NULL)
			pHeadNode = pListNode;
		
	}
	
	return pHeadNode;
}

int main(int argn,char*argc[])
{
	int array1[3]={2,4,9};
	int array2[3]={5,6,4};
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	struct ListNode* newList = NULL;
	
	if((l1 = createList(3,array1)) == NULL){
		printf("create l1 failed\n");
		return RETURN_ERROR;
		
	}
	printf("create l1 list success\n");
	traverseList(l1);
	
	if((l2 = createList(3,array2)) == NULL){
		printf("create l2 failed\n");
		return RETURN_ERROR;
	}
	printf("create l2 list success\n");
	traverseList(l2);
	
	newList = addTwoNumbers(l1,l2);
	if(newList != NULL){
		printf("Get New List");
		traverseList(newList);
	}

	
	printf("delete l1 list\n");
	deleteList(l1);
	printf("delete l2 list\n");
	deleteList(l2);
	printf("delete newlist\n");
	deleteList(newList);
	
	return RETURN_OK;
}