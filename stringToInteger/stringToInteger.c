#include <stdio.h>
#include <limits.h>

int myAtoi(char *str)
{
	int flag=1,res=0,dig;  
    while(*str==' ') str++;  
    if(*str=='-'){  
        flag=-1;  
        str++;  
    }else if(*str=='+'){  
        str++;  
    }  
    while(*str){  
        if(*str<'0' || *str>'9'){  
            return flag*res;  
        }  
        dig=*str-'0';  
        if(flag==1 && res*10.0+dig>INT_MAX){  
            return INT_MAX;  
        }else if(flag==-1 && -res*10.0-dig<INT_MIN){  
            return INT_MIN;  
        }  
        res= res*10+dig;  
        str++;  
    }  
    return flag*res;  

}

int main(int argc, char const *argv[])
{

	char * str0; //	str0.size() == 0; // 后面的半句：可写可不写，字符串默认初始化为空串 
	char * str1="1ab3";  // 应返回1
	char * str2="18446744073709551617";	
	char * str3="- +899999 ";
	char * str4="    010"; // 应返回10
	char * str5="   +0 123";
	char * str6="13  456"; // 123
	char * str7="   - 321";

	printf("%d\n", myAtoi(str0));
	printf("%d\n", myAtoi(str1));
	printf("%d\n", myAtoi(str2));
	printf("%d\n", myAtoi(str3));
	printf("%d\n", myAtoi(str4));
	printf("%d\n", myAtoi(str5));
	printf("%d\n", myAtoi(str6));
	printf("%d\n", myAtoi(str7));
	return 0;
}