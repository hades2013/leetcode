/*
* Given an array S of n integer, find three integers in S such that sum is 
*  closest to a given numbers ,  return three integer
* athor: hades 
* date: 2018-3-1 
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ABS(x) ((x)>0?(x):-(x))

void quickSort(int* nums,int first,int end){  
    int l=first,r=end;  
    if(first>=end)return;  
    int temp=nums[l];  
    while(l<r){  
        while(l<r && nums[r]>=temp)r--;  
        if(l<r)nums[l]=nums[r];  
        while(l<r && nums[l]<=temp)l++;  
        if(l<r)nums[r]=nums[l];  
    }  
    nums[l]=temp;  
    quickSort(nums,first,l-1);  
    quickSort(nums,l+1,end);  
}  
int threeSumClosest(int* nums, int numsSize, int target) {
    int begin,end,i,sum,Min=INT_MAX;  
    quickSort(nums,0,numsSize-1);  
    for(i=0;i<numsSize-2;i++){  
        if(i>0 && nums[i]==nums[i-1])continue;  
        begin=i+1;end=numsSize-1;  
        while(begin<end){  
            sum=nums[i]+nums[begin]+nums[end];  
            if(ABS(sum-target)<ABS(Min))Min=sum-target;  
            if(sum==target)return target;  
            else if(sum>target)end--;  
            else begin++;  
        }  
    }  
    return Min+target; 
}

int main(int argc, char const *argv[])
{
	int nums[]= {-1, 2, 1, -4}; 
	int target = 1;  
	int  numsSize = sizeof(nums)/sizeof(int); 
	int result; 
	result = threeSumClosest(nums, numsSize, target); 

	printf("the sum that is closest to the target is : %d\n", result);
	/* code */
	return 0;
}