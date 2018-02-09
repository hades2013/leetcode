#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *number;
	int *min; 
	int top; 
	int maxSize; 
}MinStack; 

MinStack *minStackCreate(int maxSize)
{
	MinStack *stack; 
	stack = (MinStack *)malloc(sizeof(MinStack));
	stack->number = (int *)malloc(sizeof(int) * maxSize);
	stack->min = (int *)malloc(sizeof(int) * maxSize);
	stack->top = 0; 
	stack->maxSize = maxSize;
	return stack;
	
}

void minStackPush(MinStack *stack, int element)
{
	int top = stack->top; 
	if(top >= stack-> maxSize -1)
		return; 
	stack->number[top] = element; 
	if(top == 0)
		stack->min[top] = element; 
	else{
		int min = stack->min[top - 1];
		if(element < min)
			stack->min[top] = element;
		else
			stack->min[top] = min;  
	}
	stack->top++;
}

void minStackPop(MinStack *stack)
{
	if(stack->top == 0)
		return;
	stack->top--; 
}

int minStackTop(MinStack * stack)
{
	if(stack->top == 0)
		return;
	return stack->number[stack->top -1];
}

int minStackGetMin(MinStack *stack)
{
	if(stack->top == 0)
		return;
	return stack->min[stack->top -1];
}

void minStackDestory(MinStack *stack)
{
	free(stack->min);
	free(stack->number);
	free(stack);
}


int main(int argc, char const *argv[])
{
	int number; 
	int maxSize;
	int element; 
	int i;
	MinStack *stack = NULL;
	printf("input your maxSize:");
	scanf("%d", &maxSize);
	stack = minStackCreate(maxSize);
	printf("input your number: ");
	for (i =0; i < maxSize && i < 10; ++i)
	{
		scanf("%d", &element);
		minStackPush(stack, element); 
	}
	printf("get stack top: %d\n", minStackTop(stack));
	printf("get stack min: %d\n", minStackGetMin(stack));
	minStackPop(stack);
	printf("get stack top: %d\n", minStackTop(stack));
	printf("get stack min: %d\n", minStackGetMin(stack));
	minStackDestory(stack);

	return 0;
}