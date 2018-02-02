#include <stdio.h> 
#include <stdlib.h>

int climbStairsC(int n)  
{  
    if (n < 4) return n;  
    int a = 2, b = 3, c = 5;
    int i;   
    for (i = 5; i <= n; i++)  
    {  
        a = c;  
        c = b+c;  
        b = a;  
    }  
    return c;  
}  

int climbStairsB(int n) {
    int res = 0;
    int t1 = 1;
    int t2 = 1;
    
    if(n <= 1)
     	return n;
        
    while(n >= 2){
        res = t1 + t2;
        t1 = t2;
        t2 = res;
        n--;
    }
    return res;
}

int climbStairsA(int n) {
    int* store = (int *)malloc(sizeof(int)*(n+1));
    int i;

    store[0] = 1;    
    store[1] = 1;

    for(i = 2;i<n;i++){
        store[i] = store[i-1]+store[i-2];
    }
    int tmp = store[n-1]+store[n-2];
    free(store);
    return tmp;
}

int main(int argc, char const *argv[])
{
	int n; 
	int ret; 
	printf(" input your n stairs:");
	scanf("%d", &n);
	ret = climbStairsC(n);
	printf("the distant from top is : %d\n", ret);
	return 0;
}