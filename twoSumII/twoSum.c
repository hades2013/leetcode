#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *numbers, int numSize, int target, int *returnSize)
{
	int i, j, k, flag = 0;
	i = 0; 
	j = numSize -1; 
	while(numbers[i] + numbers[j] != target){
		if(numbers[i] + numbers[j] > target)
			j --; 
		else 
			i++; 
	}	
	int *result = (int *)malloc(sizeof(int)*(*returnSize));
	result[0] = i+1; 
	result[1] = j+1;
	printf("%d  %d\n", i, j);
	return result; 
}

int main(int argc, char const *argv[])
{
	int numbers[] = {2, 7, 11, 15}; 
	int target = 9; 
	int len = sizeof(numbers)/sizeof(int);
	int returnSize = 2; 
	int *result;
	result = twoSum(numbers, len, target, &returnSize); 
	printf("%d %d\n",result[0], result[1]);
	/* code */
	return 0;
}