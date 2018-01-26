#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool  isValid(char* s) {  
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
	char *str = "(1123, rsf[9[0]8}]sfds(44))";
	bool result = isValid(str);
	printf("result == %d\n", result);
	return 0;
}