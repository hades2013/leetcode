#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSumShort(int* nums, int numsSize, int target);

#define LIST_LENGTH 100

typedef struct Item Item;

struct Item
{
    int value;
    int index;
    Item * next;
};

typedef struct List
{
    Item *head;
    Item *end;
} List;

void insertItem(List *list, Item *item)
{
    int key = ( item->value / 2 ) % LIST_LENGTH;
    
    if ( !list[key].head )
    {
        list[key].head = item;
        list[key].end = item;
    }
    else
    {
        list[key].end->next = item;
        list[key].end = item;
    }
    
}

int searchValue(List *list, int value)
{
    int key = (value / 2) % LIST_LENGTH;
    
    Item *p = list[key].head;
    
    while(p)
    {
        if(value == p->value)
        {
            return p->index + 1;
        }
        p = p->next;    
    }
    return 0;
}

void listFree(List *list)
{
	int i;
    for(i=0; i<LIST_LENGTH; i++)
    {
        
        Item *p, *q;
        p = list[i].head;
        
        while(p)
        {
            q = p->next;
            free(p);
            p = q;    
        }
        
    }
    
    free(list);
}

int* twoSumHash(int* nums, int numsSize, int target) {
	int i;
    int *res = (int*)malloc(2 * sizeof(int));
    List list[LIST_LENGTH];
    memset(list, 0, sizeof(List) * LIST_LENGTH);
    Item item[numsSize];
    memset(item, 0, sizeof(Item) * numsSize);

    for(i=0; i<numsSize; i++)
    {    
        item[i].value = nums[i];
        item[i].index = i;
        insertItem(list, &item[i]);
    }
    
    for(i=0; i<numsSize; i++)
    {
        int x = i + 1;
        int y = searchValue(list, target - nums[i]);

        if(x && y && (x ^ y))
        {
            res[0] = x < y ? x : y;
            res[1] = x + y - res[0];
            break;
        }
    }
    
    return res;
}

int* twoSumTwo(int* nums, int numsSize, int target) {
	int i; 
    if(numsSize < 100)
    {
        return twoSumShort(nums, numsSize, target);
    }
    int *res = (int*)malloc(2 * sizeof(int));
    List *list = (List*)malloc(sizeof(List) * LIST_LENGTH);
    memset(list, 0, sizeof(List*) * LIST_LENGTH);
    for(i=0; i<numsSize; i++)
    {
        Item *item = (Item*)malloc(sizeof(Item));
        item->value = nums[i];
        item->index = i;
        item->next = NULL;
        insertItem(list, item);
    }
    
    for(i=0; i<target; i++)
    {
        int x = searchValue(list, i);
        int y = searchValue(list, target - i);

        if(x && y)
        {
            res[0] = x < y ? x : y;
            res[1] = x + y - res[0];
            break;
        }
    }
    listFree(list);
    return res;
}

int* twoSumOne(int* nums, int numsSize, int target) {
	int i, j;
    int *indices = (int*)malloc(2 * sizeof (int));
    for(i=0; i<numsSize-1; i+=2)
    {
        if(nums[i] + nums[i+1] == target)
        {
            indices[0] = i + 1;
            indices[1] = i + 2;
            return indices;
        }
        else
        {
            for(j=i+2; j<numsSize; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    indices[0] = i + 1;
                    indices[1] = j + 1;
                    return indices;
                }
                else if(nums[i + 1] + nums[j] == target)
                {
                    indices[0] = i + 2;
                    indices[1] = j + 1;
                    return indices;
                }
            }
        }   
    }
    return NULL;
}

int* twoSumShort(int* nums, int numsSize, int target) {
	int i, j;
    int *indices = (int*)malloc(2 * sizeof (int));
    for(i=0; i<numsSize-1; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
	int arry[]={10, 7, 2, 4, 11, 14};
	int target = 9; 
	size_t n = sizeof(arry)/sizeof(int);
	int *nums;
	nums = twoSumHash(arry, (int)n, target);

	printf("%d  %d\n", nums[0], nums[1]);
	return 0;
}