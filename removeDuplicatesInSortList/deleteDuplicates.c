#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val; 
	struct ListNode *next;
};
struct ListNode *deleteDuplicatesB(struct ListNode *head)
{
	if(head == NULL)
        return head;
    struct ListNode *pre = head;
    struct ListNode *cur = head->next;
    while(cur!= NULL)
    {
        if(cur->val == pre->val)
            pre->next = cur->next;
        else    
            pre = cur;
        cur = cur->next;
    }
    return head;
}

struct ListNode *deleteDuplicatesA(struct ListNode *head)
{
	struct ListNode *tmp, *temp, *p; 
	p =head;
	if(head ==NULL)
		return NULL;
	temp = tmp = NULL;
	while(p->next != NULL){
		tmp = p->next; 
		if(p->val == tmp->val){
			if(tmp->next != NULL){
				temp = p->next->next; 
				p->next->next = NULL;
				p->next = temp;
			}
			else{
				p->next = NULL;
				break; 
			}
		}
		else{
			p = tmp;
		}
	}
	return head; 
}

void create(struct ListNode *list)
{
	printf("enter a number -999 to stop\n");
	scanf("%d", &list->val);
	if(list->val == -999)
		list->next = NULL;
	else{
		list->next =(struct ListNode *)malloc(sizeof(struct ListNode));
		create(list->next);
	}
}

int main(int argc, char const *argv[])
{
	struct ListNode *head, *list, *result; 
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	create(head);
	//while(head->next != NULL){
	//	list = head;
	//	printf("%d->", list->val);
	//	head = list->next; 
	//}
	result = deleteDuplicatesA(head);
	while(result->next != NULL){
		list = result; 
		printf("%d->", list->val);
		result = list->next; 
	}
	printf("\n");
	return 0;
}