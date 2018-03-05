/*
* given a linked list, swap every two adjacent nodes and return its head;
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-5
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

struct ListNode* swapPairs(struct ListNode* head) {
     if(head == NULL || head->next == NULL) return head;
    
    struct ListNode *tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;
    return tmp;  
}

int main(int argc, char const *argv[])
{
	struct ListNode *head, *result; 
	head = (struct ListNode *)malloc(sizeof(struct ListNode)); 
	createListNode(head);
	result = swapPairs(head);
	while(result){
		printf("%d -> ", result->val);
		result = result->next; 
	}
	printf("\n");
	return 0;
}