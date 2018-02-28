/*
* integer to Roman 
* athor: hades 
* date: 2018-2-28 
* I=1, V=5, X=10, L,50, C=100, D=500, M=1000
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char* intToRomanC(int num) {
	char* M[ 4] =  {"", "M", "MM", "MMM"}; /*1000*/
	char* C[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; /*100*/
	char* X[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; /*10*/
	char* I[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; /*1, 2, 3, 4, 5, 6, 7...*/
    char*str = calloc(100,1);
    memcpy(str, M[num/1000], strlen(M[num/1000]));
    memcpy(str + strlen(M[num/1000]), C[(num%1000)/100], strlen(C[(num%1000)/100]));
    memcpy(str + strlen(M[num/1000]) + strlen(C[(num%1000)/100]), X[(num%100)/10], strlen(X[(num%100)/10]));
    memcpy(str + strlen(M[num/1000]) + strlen(C[(num%1000)/100]) + strlen(X[(num%100)/10]), I[num%10], strlen(I[num%10]));
    return str;
}

char* intToRomanB(int num) {
    char *M[] = {"", "M","MM","MMM"};
    char *C[] = {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char *X[] = {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char *I[] = {"", "I","II","III","IV","V","VI","VII","VIII","IX"};
    char *ret = (char *)malloc(sizeof(char)*100);
    memset(ret, 0, 100);
    strcat(ret, M[num/1000]);
    strcat(ret, C[num/100%10]);
    strcat(ret, X[num/10%10]);
    strcat(ret, I[num%10]);
    return ret;
}

char* intToRomanA(int num) {
    int ct=0, qt,i,j;
    int nums[7]={1,5,10,50,100,500,1000};
    char chars[8]="IVXLCDM";
    char* r = (char*)malloc(sizeof(char)*10);
    char* head = r;
    for(i=6;i>=0;i--){
        ct=num / nums[i];
        num %= nums[i];
        if(ct>0){
            if((nums[i]==5 || nums[i]==50 || nums[i]==500) && num/nums[i-1]*nums[i-1] == nums[i]-nums[i-1]){ // solve for anything like 95, 927 -> XCV, CMXXVII
                *r++ = chars[i-1];
                *r++ = chars[i+1];
                num = num % nums[--i];
            }else if((nums[i]==1 || nums[i]==10 || nums[i]==100) && ct*nums[i] == nums[i+1] - nums[i]){ //solve for anything like 45, 467 -> XLV, CDVII
                *r++ = chars[i];
                *r++ = chars[i+1];
            }else{
                int j;
                for(j=0;j<ct;j++)
                    *r++ = chars[i];
            }
        }
    }
    *r = '\0';
    return head;
    
}

int main(int argc, char const *argv[])
{
	int num;
	char *result = NULL;  
	printf("please input your numbers:");
	scanf("%d", &num);
	result = intToRomanA(num);
	printf("the Roman numbers is : %s\n", result); 
	result = intToRomanB(num);
	printf("the Roman numbers is : %s\n", result); 
	result = intToRomanC(num);
	printf("the Roman numbers is : %s\n", result); 
	return 0;
}