#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinaryB(char* a, char* b) {
    int aLen = strlen(a);
    int bLen = strlen(b);
    char *tmp = NULL; 
    //make a the longer string
    if(aLen<bLen){
        tmp = a;
        a = b;
        b = tmp;
        int tmpVal = aLen;
        aLen = bLen;
        bLen = tmpVal;
    }
    int aIndex = aLen-1;
    int bIndex = bLen-1;

    int carry = 0;
    while(bIndex>=0||aIndex>=0){
        int aVal = a[aIndex]-'0';
        int bVal = 0;
        if(bIndex>=0)
            bVal = b[bIndex--]-'0';

        int val = aVal+bVal+carry;
        a[aIndex--] = val%2 + '0';
        carry = val/2;

        if(bIndex<0&&!carry)
            return a;
    }

    if(!carry)
        return a;
    char *aa = (char *)malloc(sizeof(char)*(aLen+2));
    memset(aa, 0, sizeof(char)*(aLen+2));
    aa[0] = '1';

    strcpy(aa+2,a);
    return aa;
}
/**
 * 解题思路：另外申请一个数组用于保存相加后的二进制字符串，注意字转整型与整型转字符。注意二进制之间的进位。
 */
char *addBinaryA(char *a, char *b) {
    int i,j, temp,temp1,lenA,lenB,len;
    char *str;
    lenA = strlen(a);
    lenB = strlen(b);
    len = lenA>lenB?lenA:lenB;
    str= (char *)malloc((len+2)*sizeof(char));//申请的空间要大于最大的字符串长度加1+1，第一个1指字符串相加后可能进位，第二个1指字符串最后的'\0'结束字符
    memset(str,0,(len+2)*sizeof(char));
    j = len-1;temp  = 0;
    for(i=len;i >= 0 && lenA > 0 && lenB > 0; i--){
        *(str+i) = ((*(a+lenA-1)-'0') + (*(b+lenB-1)-'0') + temp)%2 + '0';
        temp = ((*(a+lenA-1)-'0') + (*(b+lenB-1)-'0') + temp)/2;
        lenA--;lenB--;
    }
    if(lenA == 0){//则对b字符串进行赋值给str
        for(; lenB > 0;i--){
            *(str+i) = ((*(b+lenB-1)-'0') +temp)%2 + '0';
            temp = ((*(b+lenB-1)-'0') +temp)/2;
            lenB--;
        }
    }else if(lenB == 0){//对a字符串进行赋值给str
        for(; lenA >0;i--){
            *(str+i) = ((*(a+lenA-1)-'0') + temp)%2+'0';
            temp = ((*(a+lenA-1)-'0') + temp)/2;
            lenA--;
        }
    }
    if(temp == 1) {*(str+i) = temp+'0';return str+i;}//若temp进位为1，则赋值给str
    return str+i+1;
}

int main(int argc, char const *argv[])
{
    char *binaryA = "101010110";
    char *binaryB = "101110111";
    char *p ; 
    p = addBinaryB(binaryA, binaryB);
    printf("the add result: %s\n", p);
    return 0;
}