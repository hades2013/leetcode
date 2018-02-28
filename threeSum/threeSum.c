/*
* Return an array of array of size *returnSize. 
* Note: the returned array must b malloced, assume caller calls free(); 
* athor: hades 
* date: 2018-2-28 
* 
*/
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
      return (*(int*)a - *(int*)b);
}

int** threeSumB(int* nums, int numsSize, int* returnSize) {
    int **sol = (int **)malloc(sizeof(int*) * 100000);
    int c = 0;
    int i; 
    
    if (numsSize < 3) {
        *returnSize = c;
        return sol;
    }
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (i = 0; i < numsSize - 2 && nums[i] <= 0; i++) {
        if (nums[i] == 0) {
            if (nums[i + 1] == 0 && nums[i + 2] == 0) {
                sol[c] = (int *)malloc(sizeof(int) * 3);
                sol[c][0] = 0;
                sol[c][1] = 0;
                sol[c][2] = 0;
                c++;
                break;
            }
        }
    
        int j = i + 1;
        int k = numsSize - 1;
        
        int prev[3];
        while (j < k) {
            while (j < k - 1 && nums[j] == nums[j + 1] && nums[j + 1] == nums[j + 2]) j++;
            while (j < k + 1 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2]) k--;
            
            int sum = nums[i] + nums[j] + nums[k];
            
            if (sum < 0) j++;
            if (sum > 0) k--;
            if (sum == 0) {
                if (prev[0] == nums[i] && prev[1] == nums[j] && prev[2] == nums[k]) {
                    j++;
                    k--;
                    continue;
                }
                prev[0] = nums[i];
                prev[1] = nums[j];
                prev[2] = nums[k];
                sol[c] = (int *)malloc(sizeof(int) * 3);
                sol[c][0] = nums[i];
                sol[c][1] = nums[j];
                sol[c][2] = nums[k];
                c++;
                j++;
                k--;
            }
        }
        
        while (i < numsSize - 2 && nums[i] == nums[i + 1]) i++;
    }
    
    *returnSize = c;
    return sol;
}

void quickSort(int* nums,int first,int end){
    int temp,l,r;
    if(first>=end)return;
    temp=nums[first];
    l=first;r=end;
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
int** threeSumA(int* nums, int numsSize, int* returnSize) {
    int i,sum,top=-1,begin,end;
    int** res=(int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);
    if(numsSize<3){
        *returnSize=0;
        return res;
    }
    quickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize;i++){
        if(nums[i]>0)break;
        if(i>0 && nums[i]==nums[i-1])continue;
        begin=i+1;end=numsSize-1;
        while(begin<end){
            sum=nums[i]+nums[begin]+nums[end];
            if(sum==0){
                top++;
	            res[top]=(int*)malloc(sizeof(int)*3);
	            res[top][0]=nums[i];res[top][1]=nums[begin];res[top][2]=nums[end];
	            begin++;end--;
	            while(begin<end && nums[begin]==nums[begin-1])begin++;
	            while(begin<end && nums[end]==nums[end+1])end--;
            }else if(sum>0) end--;
            else begin++;
        }
    }
    *returnSize=top+1;
    return res;
}

int main(int argc, char const *argv[])
{
	int nums[] = {-1, 0, 1, 2, -1, -4, 5, -5, 0}; 
	int numsSize = sizeof(nums)/sizeof(int); 
	int returnSize = 3; 
	printf("%d\n",numsSize);
	int **result = NULL;
	result = threeSumB(nums, numsSize, &returnSize); 
	printf("%d\n", returnSize);
	int i, j; 
	for(i = 0; i < returnSize; i++){
		for(j = 0; j < 3; j++){
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

