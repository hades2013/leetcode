/*
* given a string containing (){}[]. determine if the string is valid
* athor: hades
* date: 2018-2 
* modify date : 2018-3-2
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValidB(char* s) {
     int len = strlen(s);
    if( len%2 != 0 )
    {
        return false;
    }
    
    int limit = len / 2;
    char *stack = malloc(limit);
    int idx = 0;
    char cur, peek;
    int i; 
    for(i = 0; i < len; ++i)
    {
        cur = s[i];
        if(cur == '(' || cur == '[' || cur =='{')
        {
            if(idx == limit)
            {
                return false;
            }
            else
            {
                stack[idx++] = cur;
            }
        }
        else
        {
            if(idx == 0)
            {
                return false;
            }
            peek = stack[idx -1];
            if( (peek == '(' && cur == ')')
                || (peek == '[' && cur == ']')
                || (peek == '{' && cur == '}') )
            {
                idx--;
            }
        }
    }
    return idx == 0;
}

bool  isValidA(char* s) {  
    char *a;  
    int top; //top of stack  
      
    size_t n = strlen(s);  
    a = (char*)malloc(sizeof(char*) * (n+1));  
      
    top = -1;  
      
    int i;  
    for( i = 0 ; i< n ; i++ ){  
        if (s[i]=='{' || s[i]== '[' || s[i] == '(')  
            a[++top]=s[i];  
          
        else if (top==-1 && (s[i]=='}' || s[i]== ']' || s[i] == ')'))  
            return 0;  
          
        else if ( (s[i]==')'&& a[top]!='(') || (s[i]=='}'&& a[top]!='{')  
                 ||(s[i]==']'&&a[top]!='[') )  
            return 0;  
        else if( (s[i]==')'&& a[top]=='(')  || (s[i]=='}'&& a[top]=='{')  
                || (s[i]==']'&& a[top]=='[') )  
            top--;  
    }  
      
    if(top == -1) return 1;  
    else return 0;  
}  
int main(int argc, char const *argv[])
{
	char *str = "(1123, r{sf[9[0]8]}sfds(44))";
	bool result = isValidA(str);
	printf("result == %d\n", result);
    result = isValidB(str);
    printf("result == %d\n", result);
	return 0;
}