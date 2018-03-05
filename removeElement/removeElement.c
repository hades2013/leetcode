/*
* given an array and a value, remove all instance of that value in-place
* and return a new length; 
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-5
*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i, j; 
    for(i =0, j=0; i< numsSize; i++){
        if(nums[i] != val){
            nums[j++] = nums[i];
        } 
    }
    return j; 
    
}

int main(int argc, char const *argv[])
{
	int nums[] = {2, 3, 1, 5, 6, 7, 8};
	int numsSize = sizeof(nums)/sizeof(int); 
	printf("the nums\'s length: %d\n", numsSize);
	int value =  5; 
	int ret, i; 
	ret = removeElement(nums, numsSize, value);
	printf("after remove, the length: %d \n", ret);
	for(i = 0; i< ret ; i++)
		printf("%d , ", nums[i]);
	printf("\n");
	return 0;
}