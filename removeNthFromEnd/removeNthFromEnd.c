/*
* given a linked list, remove the Nth node frome the end 
* athor: hades
* date: 2018-3-1
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val; 
	struct ListNode* next; 
};

void createListNode(struct ListNode *list)
{ 
	printf("enter a number or -999 to stop\n");
	scanf("%d", &list->val);
	if(list->val== -999)
		list->next = NULL; 
	else{
		list->next =(struct ListNode *)malloc(sizeof(struct ListNode));
		createListNode(list->next); 
	}   
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode *front = head; 
	struct ListNode *behind = head; 
	while(front != NULL){
		front = front->next; 
		if(n--<0)
			behind = behind->next; 
	}
	if(n == 0) 
		head = head->next; 
	else 
		behind->next = behind->next->next; 
	return head; 
}
int main(int argc, char const *argv[])
{
	struct ListNode *head, *list, *result; 
	int n; 
	head = (struct ListNode *)malloc(sizeof(struct ListNode)); 
	createListNode(head);
	printf("remove from end, n :");
	scanf("%d", &n);
	result = removeNthFromEnd(head, n); 
	while(result){
		printf("%d -> ", result->val);
		result = result->next; 
	}
	printf("\n");
	return 0;
}