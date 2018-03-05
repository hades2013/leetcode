/*
* given a linked list, reverse the nodes of a linked list k at a time 
* and return its modified list; 
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

int createListNode(struct ListNode *list)
{ 
	static int count = 0;
	printf("enter a number or -99 to stop\n");
	scanf("%d", &list->val);
	++count; 
	if(list->val== -99)
		list->next = NULL; 
	else{
		list->next =(struct ListNode *)malloc(sizeof(struct ListNode));
		createListNode(list->next); 
	}
	return count;    
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *current, *previous, *scout;
    int count;
    
    scout = current = head;
    previous = NULL;
    count = 0;

    while (scout) {
        
        ++count;

        if (k > 1 && count == k) {
            
            scout = scout->next;
            struct ListNode *first, *following;
            first = current;
            
            while (count-- > 1) {
                
                following = current->next;
                current->next = following->next;
                following->next = first;
                first = following;
            }
            
            if (previous)
                previous->next = first;
            else
                head = first;
                
            previous = current;
            current = scout;
            count = 0;
        }
        else
            scout = scout->next;
    }
    
    return head;
    
}

int main(int argc, char const *argv[])
{
	struct ListNode *head, *list, *result; 
	int k, count; 
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	count = createListNode(head);
	printf("input the 0 < k < %d : ", count);
	scanf("%d", &k);
	result = reverseKGroup(head, k);
	while(result){
		printf("%d -> ", result->val);
		result = result->next; 
	}
	printf("\n");
	return 0;
}
