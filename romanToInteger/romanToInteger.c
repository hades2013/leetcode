/*
* integer to Roman 
* athor: hades 
* date: 2018-2-28 
* I=1, V=5, X=10, L,50, C=100, D=500, M=1000
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


int romanToIntB(char *s) {
#define _M 1000
#define _D 500
#define _C 100
#define _L 50
#define _X 10
#define _V 5
#define _I 1

    int result  = 0;
    int i;
    int last = _M;
    for(i = 0;i < strlen(s);i++)
    {
        switch (s[i])
        {
            case 'M':
                result = (last >= _M ? result + _M:result + _M - (last << 1));
                last = _M;        
            break;
            case 'D':
                result = (last >= _D ? result + _D:result + _D - (last << 1));
                last = _D;
            break;
            case 'C':
                result = (last >= _C ? result + _C:result + _C - (last << 1));
                last = _C;
            break;
            case 'L':
                result = (last >= _L ? result + _L:result + _L - (last << 1));
                last = _L;
            break;
            case 'X':
                result = (last >= _X ? result + _X:result + _X - (last << 1));
                last = _X;
            break;
            case 'V':
                result = (last >= _V ? result + _V:result + _V - (last << 1));
                last = _V;
            break;
            case 'I':
                result = (last >= _I ? result + _I:result + _I - (last << 1));
                last = _I;
            break;
        }
        
    }
    return result;
}

int romanToIntA(char* s) {
    int R[128] = {0};
    R['I'] = 1;
    R['V'] = 5;
    R['X'] = 10;
    R['L'] = 50;
    R['C'] = 100;
    R['D'] = 500;
    R['M'] = 1000;

    char*sp = s;
    char*prev = "M";
    int sum = 0;
    while(*sp != 0) {
        if(R[sp[0]] > R[prev[0]]) {
            sum += R[sp[0]] - 2*R[prev[0]];
        } else {
            sum += R[sp[0]];
        }
        prev = sp;
        sp += 1;
    }

    return sum;
}

int main(int argc, char const *argv[])
{
	char roman[128];
	int  result; 
	while(gets(roman)){
		result = romanToIntA(roman); 
		printf("the integer: %d\n", result);
		result = romanToIntB(roman);
		printf("the integer: %d\n", result);
	}
	return 0;
}