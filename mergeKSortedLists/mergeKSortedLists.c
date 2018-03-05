/*
* merge K sorted linked lists and return it as a new lists
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
  if( (l1 == NULL) && (l2 == NULL)) return NULL;
  else if(l1 == NULL)               return l2;
  else if(l2 == NULL)               return l1;
  
  if(l1->val > l2->val)
  {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
  else
  {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  }
  return NULL;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  if(listsSize == 0)      return NULL;
  else if(listsSize == 1) return lists[0];
  else if(listsSize == 2) return mergeTwoLists(lists[0], lists[1]);

  //divide and conquor if listsSize is still > 3
  return mergeTwoLists(mergeKLists(lists, listsSize/2),
                       mergeKLists(lists+listsSize/2, listsSize - listsSize/2));
    
    
}

int main(int argc, char const *argv[])
{
	struct ListNode **head, *list1, *list2, *result;
	int count; 
	list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	count = createListNode(list1);
	printf("the count: %d\n", count);
	printf("input list2 : \n");
	count = createListNode(list2);
	printf("the count: %d\n", count);
	head = (struct ListNode **)malloc(sizeof(struct ListNode)* 2);
	head[0] = list1;
	head[1] = list2; 
	result = mergeKLists(head, count - 2 ); 
	while(result){
		printf("%d -> ", result->val);
		result = result->next; 
	}
	printf("\n");
	return 0;
}