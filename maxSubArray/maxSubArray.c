#include <stdio.h>

int maxSubArray(int *nums, int numsSize)
{
	int maxSum = nums[0], thisSum=nums[0];
	int i; 
	for(i = 1; i < numsSize; i++){
		if(thisSum < 0)
			thisSum=nums[i];
		else
			thisSum+=nums[i];
		if(thisSum > maxSum)
			maxSum = thisSum;
	}

	return maxSum;
}

int maxSubArrayA(int *nums, int numsSize, int l, int r)
{
	int maxSum = nums[0], thisSum=nums[0];
	int i; 
	int new_l;
	for(i = 1; i < numsSize; i++){
		if(thisSum < 0){
			thisSum=nums[i];
			new_l =i; 
		}
		else
			thisSum+=nums[i];
		if(thisSum > maxSum)
			maxSum = thisSum;
			l = new_l;
			r = i; 
	}

	return maxSum;

}

int main(int argc, char const *argv[])
{
	//int arr[]={1,9,3,8,11,4,5,6,4,1,9,7,1,7};
	int arr[]={-2,1,-3,4,-1,2,1,-5,4};
	int len = sizeof(arr)/sizeof(int);
	int maxSum; 
	maxSum = maxSubArray(arr, len);
	printf("maxSubArray : %d\n", maxSum); 
	return 0;
}