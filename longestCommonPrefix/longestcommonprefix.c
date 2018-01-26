#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestcommonprefixA(char **strs, int strssize)
{	
	int len = strlen(strs[0]);
	char *temp = NULL;
	temp = malloc(sizeof(char) * (len+1));
	strcpy(temp, strs[0]);
	int i, j; 

	if(strssize <= 0)
		return "";

	for(i =0; i< strssize; i++){
		j=0;
		while(temp[j] && strs[i][j] && temp[j] == strs[i][j])
			j++;
		temp[j]='\0';
	}
	return temp;
}

char* longestcommonprefixB(char** strs, int strsSize) 
{
    int i=0; int j=0;int index;int tempindex=0;
    if(strsSize<1)
    return "";
    index=strlen(strs[0]);
    char *a;
    a= malloc(sizeof(char)*(index+1));
    strcpy(a,strs[0]);
    for(i=1;i<strsSize;i++)
    {   tempindex=0;
        for(j=0;j<index;j++)
        { 
            if(a[j]==strs[i][j])
            tempindex++;
            else
            {a[j]='\0';
             break;
            }
        } 
          if (tempindex==0)return ("");
          if(tempindex<index)index=tempindex;
        
    }
    return a;
    
}

int main(int argc, char const *argv[])
{
	char *str[]={"abcsfjosjfo", "abceijfieji", "abc385ru8", "abc293jf9efj", "abcfjoewfjo"};
	int len = sizeof(str)/sizeof(str[0]);
	int i, j;
	char *p = NULL;

	for(i=0; i< len; i++){
			printf("%s\n", str[i]);
	}
	p = longestcommonprefixB(str, len);
	printf("the str\'s longest common prefix is : %s\n", p);

	return 0;
}