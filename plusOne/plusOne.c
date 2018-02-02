#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int i; 
	int dex =1; 
	int tmp = 0; 
	int *ret; 
	for(i = digitsSize -1 ; i>= 0; i--){
		tmp = (digits[i]+dex)%10; 
		dex = (digits[i]+dex)/10; 
		digits[i]=tmp;
	}
	if(dex == 1){
		ret = (int *)malloc(sizeof(int)* digitsSize); 
		ret[0] =1;
		for(i=0; i<digitsSize; i++)
			ret[i+1] = digits[i];
			
		*returnSize = digitsSize;
		return ret;	
	}
	if(dex == 0){
		*returnSize = digitsSize; 
		return digits; 
	}
}

int main(int argc, char const *argv[])
{
	int number; 
	int digitsSize = 0;
	int *returnSize= NULL;
	int *p; 
	int digits[32]={0};
	int i; 
	printf("input your digitsSize is:");
	scanf("%d", &digitsSize); 
	for(i =0;  i < digitsSize; i++){
		scanf("%d", &digits[i]);
	}

	p = plusOne(digits, digitsSize, returnSize);
	printf("%d\n", p);
	return 0;
}