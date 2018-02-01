#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10005

char *countAndSayA(int n)
{
	char s[MAXN], t[MAXN];
	strcpy(s, "1");
	strcpy(t, "");
	int cnt = 1; 
	int i, j;
	char tmp[3];

	for(i =0; i<= n ; i++){
		int len= strlen(s);
		for(j = 0; j< len; j++){
			if(s[j] == s[j+1])
				cnt++;
			else{
				tmp[0] = cnt + '0';
				tmp[1] = s[j];
				tmp[2] = '\0';
				strcat(t, tmp);
				cnt = 1;
			}
		}
		strcpy(s, t);
		strcpy(t, "");
	}
	return s; 
}
char *countAndSayB(int n)
{
	if(n == 1) return "1";
	char *cur = malloc(2);
	char *temp = NULL;
	cur[0] = '1';
	cur[1] = '0';

	int i,len, idx, j, count;
	for(i =0 ; i<=n; i++){
		len = strlen(cur);
		temp = malloc(3*len);
		memset(temp, 0, 3*len);
		count =1;
		for (idx = 1, j=0; idx < len; idx++){
			if(cur[idx] == cur[idx -1])
				count ++;
			else{
				temp[j++] = '0' +count;
				temp[j++] = cur[idx-1];
				count =1;

			}
		}
		temp[j++] = '0' + count;
		temp[j] = cur[len -1];
		free(cur);
		cur = temp;
	}
	return cur; 
}

char * countAndSayC(int n)
{
	char *seq = (char *)malloc(sizeof(char)*10000);
	char *bak = (char *)malloc(sizeof(char)*10000);
	char *tmp;
	char t; 
	int top=1, i, index, num, l, r; 

	seq[0]='1'; 
	seq[1]=0;
	while(--n){
		index = 0; 
		for(i= 0; i< top; i++){
			num =1; 
			while(i+1 < top && seq[i+1] == seq[i]){
				i++;
				num++;
			}
			l = index;
			while(num >0){
				bak[index++] = num%10 +'0';
				num/=10;
			}
			r = index -1;
			while(l < r){
				t = bak[l];
				bak[l] = bak[r];
				bak[r] = t;
				l++; 
				r--; 
			}
			bak[index++]=seq[i];
			
		}
		bak[index]=0;
		top=index;
		tmp=seq;
		seq=bak;
		bak=tmp;
	}
	free(bak);
	return seq; 
}

int main(int argc, char const *argv[])
{
	int n;
	char *str=NULL;
	printf("input your number:"); 
	scanf("%d", &n);
	str = countAndSayC(n);
	printf("%s\n", str);

	return 0;
}