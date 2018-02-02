#include <stdio.h>
#include <string.h>


int lengthOfLastWordA(char *s)
{
	char *ps =s; 
	int lastWordSize=0, wordSize=0; 
	if(!s || !*s)
		return 0; 
	while(*ps){
		if(*ps == ' '){
			if(wordSize)
			{
				lastWordSize = wordSize;
			}
			wordSize = 0;
		}
		else{
			++wordSize; 
		}
		if(*ps == ' ' && !*(ps+1)){
			wordSize = lastWordSize; 
			break;
		}
		++ps;
	}
	return wordSize;
}

int lengthOfLastWordB(const char *s)
{
	int len = 0; 
	while(*s){
		if(*s++ != ' ')
			++len; 
		else if(*s && *s != ' ')
			len = 0;
	}
	return len; 
}

int main(int argc, char const *argv[])
{
	char *str = "hello world! this is my test code!";
	int i;
	int len = strlen(str);
	i = lengthOfLastWordB(str); 
	printf("%s\n", str+len-i);
	return 0;
}