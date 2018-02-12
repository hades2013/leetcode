#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* convertToTitleB(int n) {
    char *res = (char *)calloc(8, sizeof(char));
    int i = 6;
    while(n){
        res[i--] = (char)((n-1) % 26) + 'A';
        n = (n - 1) / 26;
    }
    return res+i+1;
}

char *convertToTitleA(int n)
{
	int i = 0; 
	char *ch = malloc(255); 
	char *p = malloc(255);
	memset(ch, 0, sizeof(ch)); 
	memset(p, 0, sizeof(p));
	while(n > 0){
		n--; 
		*(ch + i) = ( n%26) + 'A'; 
		i++; 
		n = n/26;
	}
	for(i = 0; i < strlen(ch); i++){
		*(p + i) = *(ch + strlen(ch) - i - 1);
	}
	free(ch);
	return p;
}

int main(int argc, char const *argv[])
{
	char *p; 
	int n = 2014; 
	int i; 
	p = convertToTitleA(n); 
	for(i = 0; i < strlen(p); i ++)
		printf("%d ---> %s\n", i+1, p+i);
	return 0;
}