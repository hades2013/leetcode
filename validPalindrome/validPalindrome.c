#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isPanlindromeB(char *s){
	int len = strlen(s);
	if(!len) 
		return 1; 
	char *p1 =s; 
	char *p2 = s+len -1; 
	while(p1 < p2){
		if(!isalnum(*p1)){
			p1++; 
			continue; 
		}
		if(!isalnum(*p2)){
			p2++;
			continue;
		}
		if(tolower(*p1++) != tolower(*p2--))
			return 0; 
	}
	return 1;

}

char compareChar(char ch)
{
	if(ch >= 48 && ch <= 57)
		return ch; 
	else if(ch >= 65 && ch <= 90)
		return ch + 32; 
	else if(ch >= 97 && ch <= 122)
		return ch; 
	else 
		return 0; 
}
int isPanlindromeA(char *s)
{
	int i,j,length;
	char *p; 
	if(*s == '\0') 
		return 1; 
	length = 0; 
	while(*(s+length) != '\0')
		length++; 
	p = s + length -1; 
	i = j = 0; 
	while((s+j) != (p-i) && (s+j) <= (p-i)){
		if(compareChar(*(s+j)) == 0){
			j++;
			continue; 
		}
		if(compareChar(*(p-i)) == 0){
			i++; 
			continue;
		}
		if(compareChar(*(s+j)) == compareChar(*(p-i))){
			j++; 
			i++;
			continue;
		}
		else
			return 0;

	}
	return 1; 

}

int main(int argc, char const *argv[])
{
	//char *str = "A man, a plan, a canal: Panama";
	char *str = "abcdeedcba"; 
	int ret; 
	ret = isPanlindromeA(str);
	if(ret == 1)
		printf("is palindrome is true !\n");	
	else
		printf("is palindrome is false!\n");
	return 0;
}