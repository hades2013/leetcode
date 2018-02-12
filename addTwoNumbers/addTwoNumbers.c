#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list
struct ListNode {
	int val; 
	struct ListNode * next; 
};

struct ListNode* addTwoNumbersB(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* result = l1 ? l1 : l2;
    struct ListNode* carry = l1 ? l2 : l1;
    struct ListNode* node = result;
    struct ListNode* tmp;
    int c = 0;
    int s;
    while (l1 || l2) {
        s = c;
        if (l1) { s += l1->val; l1=l1->next; }
        if (l2) { s += l2->val; l2=l2->next; }
        c = s > 9 ? 1 : 0;
        node->val = c ? s - 10 : s;
        if (l1) {
            node = node->next = l1;
        } else if (l2) {
            node = node->next = l2;
        } else {
            node->next = NULL;
        }
    }
    if (c) {
        carry->val = c;
        node->next = carry;
        node = node->next;
    }
    node->next = NULL;
    return result;
}

struct ListNode *addTwoNumbersA(struct ListNode * l1, struct ListNode *l2)
{
	struct ListNode *p1 = l1; 
	struct ListNode *p2 = l2; 
	struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode)); 
	result->val = 0; 

	struct ListNode *p = NULL; 
	int c = 0; 
	while(p1 != NULL || p2 != NULL || c != 0){
		if(p == NULL)
			p = result; 
		else{ 
			p->next = (struct ListNode *)malloc(sizeof(struct ListNode)); 
			p->next->val = 0; 
			p = p->next; 
		}
		int a = (p1 == NULL? 0 : p1->val); 
		int b = (p2 == NULL? 0 : p2->val); 
		int s = (a+b+c)%10; 
		c = (a+b+c)/10; 
		p->val = s; 
		p->next = NULL; 

		p1 = (p1 == NULL ? NULL : p1->next); 
		p2 = (p2 == NULL ? NULL : p2->next); 
	}
	return result; 
}

int main(int argc, char const *argv[])
{
	int numbers1[] = { 2, 4 ,3}; 
	int numbers2[] = { 5, 6, 4}; 
	struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *result = NULL;
	struct ListNode *p = NULL; 
	int len1 = sizeof(numbers1)/sizeof(int); 
	int len2 = sizeof(numbers2)/sizeof(int); 
	int i; 
	l1->next = NULL; 
	l1->val = numbers1[0]; 
	struct ListNode *r;
	r = l1;  
	for(i = 1; i < len1 ; i++) { 
		p = (struct ListNode *)malloc(sizeof(struct ListNode)); 
		p->val = numbers1[i];
		printf("%d ", p->val); 
		r->next = p; 
		r = p; 
	}
 	printf("\n");
 	l2->next = NULL;
 	l2->val = numbers2[0];
 	r = l2; 
	for(i = 1 ; i < len2; i++){
		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->val = numbers2[i];
		printf("%d ", p->val);
		r->next = p; 
		r = p;  
	}
	printf("\n");
	result = addTwoNumbersB(l1, l2); 
	while(result){
		printf("%d ", result->val);
		result = result->next; 
	}
	printf("\n");
	return 0;
}