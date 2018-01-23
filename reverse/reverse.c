#include <stdio.h>
#include <limits.h>

typedef enum {
	false, 
	true = 1
} bool;

int reverseS(int x) {
    long long val = 0;
	do 
	{
		val = val * 10 + x % 10;
		x /= 10;
	} while (x);
	
	return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}

int reverseA(int x) {
	int nums = 0, tmpNum , tmp, i;
    bool negative = false;

    if(x<0){
        negative = true;
        x = -x;
     }
     while(x){
         tmpNum = nums;
         tmp = 0;
         for(i = 0;i<10;i++){
            tmp = tmp+tmpNum;
            if(tmp<tmpNum)
                return 0;
         }
         nums = tmp;
         nums=nums+x%10;
         x = x/10;
     }
     if(negative)
        return -1*nums;
     return nums;
}

int reverseB(int x) {
	int nums = 0, tmpNum, tmp, i;

     bool negative = false;
     if(x<0){
        negative = true;
        x = -x;
     }
     while(x){
         if(nums>(INT_MAX-x%10)/10)//成立，则一定会超
             return 0;
         nums=nums*10+x%10;
         x = x/10;
     }
     if(negative)
        return -nums;
     return nums;
}

int main(int argc, char const *argv[])
{
	int x;
	int revs; 
	scanf("%d", &x);
	printf("input number is: %d\n", x);
	revs = reverseB(x);
	printf("reverse number is; %d\n", revs);
	return 0;
}