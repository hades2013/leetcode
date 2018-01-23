#include <stdio.h>
#include <string.h>
#include <limits.h>

int reverse(int x) {  
    long long val = 0;  
    do  
    {  
        val = val * 10 + x % 10;  
        x /= 10;  
    } while (x);  
      
    return (val > INT_MAX || val < INT_MIN) ? 0 : val;  
}  

int isPalindromeB(int x)  
{ 
 	if(x < 0) return 0;  
    if(x < 10) return 1;  
    int y = 0;  
    y = reverse(x);  
    
    if (x==y)
    	return 1;
    else
    	return 0; 
} 
     

int isPalindromeA(int x) {
    int stack[10]={-1};
    if(x<0) return 0;
    if(x==0)return 1;
    int tmp;
    int i=0;
    while(x>0)
    {
        tmp=x%10;
        x=x/10;
        stack[i++]=tmp;
    }
    i=i-1;
    int j;
    for(j=0;j<=i;j++,i--)
    {
        if(stack[j]!=stack[i])
        {
            return 0;   
        }
     }
    return 1;
}

int main(int argc, char const *argv[])
{
	int num; 
	int ret; 
	scanf("%d", &num);
	ret = isPalindromeB(num);
	if(ret==1)
		printf("input number %d is Palindrome\n", num);
	else
		printf("input number %d is not Palindrome\n", num);

	return 0;
}