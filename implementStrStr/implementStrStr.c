/*
* implement strstr();
* athor: hades
* email: hades2013ac@gmail.com
* date: 2018-3-5
*/

#include <stdio.h>
#include <string.h> 

int strStr(char* haystack, char* needle) {
	char *p, *q;
	int i, len = strlen(haystack) - strlen(needle);

	for (i = 0; i <= len; i++) {
		p = haystack + i;
		q = needle;
		while (*q && *p == *q) {
			++p;
			++q;
		}
		if (*q == 0)
			return i;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	char *str1 = "hello"; 
	char *str2 = "ll";
	int ret; 
	ret = strStr(str1, str2); 
	printf("the return is : %d \n", ret);
	return 0;
}