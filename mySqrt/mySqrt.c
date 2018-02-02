#include <stdio.h> 

float InvSqrt(float x)  
{  
    float xhalf = 0.5f*x;  
    int i = *(int*)&x; // get bits for floating VALUE  
    i = 0x5f375a86- (i>>1); // gives initial guess y0  
    x = *(float*)&i; // convert bits BACK to float  
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy  
    return x;  
}  

int mySqrtB(int x) {
       // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        if (x ==0)  
            return 0;  
        double pre;  
        double cur = 1;  
        do  
        {  
            pre = cur;  
            cur = x / (2 * pre) + pre / 2.0;  
        } while (abs(cur - pre) > 0.00001);  
        return (int)cur;  
    
}


int mySqrtA(int x) {
     // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        unsigned long long begin = 0;  
        unsigned long long end = (x+1)/2;  
        unsigned long long mid;  
        unsigned long long tmp;  
        while(begin < end)  
        {  
            mid = begin + (end-begin)/2;  
            tmp = mid*mid;  
            if(tmp==x)return mid;  
            else if(tmp<x) begin = mid+1;  
            else end = mid-1;  
        }  
        tmp = end*end;  
        if(tmp > x)  
            return end-1;  
        else  
            return end;  
    
}

int main(int argc, char const *argv[])
{
	float x= 2; 
	float ret ; 
	ret = mySqrtA(x); 
	printf("the sqrt result : %f\n", ret);
	return 0;
}