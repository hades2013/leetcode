/*
* merge two sorted linked lists and return it as a new lists;
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
	printf("enter a number or -99 to stop\n");
	scanf("%d", &list->val);
	if(list->val== -99)
		list->next = NULL; 
	else{
		list->next =(struct ListNode *)malloc(sizeof(struct ListNode));
		createListNode(list->next); 
	}   
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main(int argc, char const *argv[])
{
	struct ListNode *head, *list1, *list2;
	list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	createListNode(list1);
	printf("input list2 : \n");
	createListNode(list2);
	head = mergeTwoLists(list1, list2); 
	while(head){
		printf("%d -> ", head->val);
		head = head->next; 
	}
	printf("\n");
	return 0;
}