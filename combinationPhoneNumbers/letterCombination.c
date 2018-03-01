/*
* given a digit string, return all possible letter combination that the number 
* could represent.
* athor: hades 
* date: 2018-3-1 
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[10][4] = {
    {' ', ' ', ' ', ' '}, //0
    {' ', ' ', ' ', ' '}, //1
    {'a', 'b', 'c', ' '}, //2
    {'d', 'e', 'f', ' '}, //3
    {'g', 'h', 'i', ' '}, //4
    {'j', 'k', 'l', ' '},
    {'m', 'n', 'o', ' '},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v', ' '}, //8
    {'w', 'x', 'y', 'z'} //9
};

void letterComb(char* digits, int* returnSize, char *result, int ind, char **ans)
{
    int i = 0;
    char c;
    char *letter = map[digits[0] - '0'];

    if (digits[0] == 0) {
        char *res = malloc(strlen(result) + 1);
        strcpy(res, result);
        ans[(*returnSize)] = res;
        (*returnSize)++;
        return;
    }

    while ((c = letter[i]) != ' ') {
        result[ind] = c;
        letterComb(digits + 1, returnSize, result, ind + 1, ans);
        i++;
        if (i == 4)
            break;
    }
    return;
}

char** letterCombinationsB(char* digits, int* returnSize) {
    
    int ind = 0, size = 0;
    int len = strlen(digits) + 1;
    char result[len];
    
    if (digits == NULL || strlen(digits) == 0)
        return NULL;
  
    char **ans = (char **) malloc(sizeof (char *) * 32768);
        
    memset(result, 0, len);
    
    letterComb(digits, &size, result, ind, ans);
    *returnSize = size;
    
    return ans;
}

static const char* letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combine(char* digits, int from, int to, char* result, char** combinations, int* index) {
	int i; 
	if (from <= to) {
		const char *letter = letters[digits[from] - '0'];
		for (i = 0; i < strlen(letter); ++i) {
			result[from] = letter[i];
			combine(digits, from+1, to, result, combinations, index);
		}
	} else {
		result[from] = '\0';
		combinations[*index] = malloc(sizeof(strlen(result)));
		strcpy(combinations[*index], result);
		(*index)++;
	}
}

char** letterCombinationsA(char* digits, int* returnSize) {
    if (digits == NULL) {
    	return NULL;
    }
    int digitsLength = strlen(digits);
    if (digitsLength == 0) {
    	return NULL;
    }
    int returnStrLen = 0, i;
    *returnSize = 1;
    for (i = 0; i < digitsLength; ++i) {
    	int index = (int)(digits[i] - '0');
    	if (index >= 2 && index <= 9) {
    		*returnSize *= strlen(letters[index]);
    		returnStrLen++;
    	}
    }
    char** combinations = malloc(sizeof(char*) * (*returnSize));
    char* resultStr = malloc(sizeof(returnStrLen+1));
    int* index = malloc(sizeof(int));
    *index = 0;
    combine(digits, 0, digitsLength-1, resultStr, combinations, index);
    return combinations;
}


int main(int argc, char const *argv[])
{
	char digits[128];
	char **result; 
	int returnSize = 4;
	int i;   

	while(gets(digits)){
		result = letterCombinationsB(digits, &returnSize); 
		for(i = 0; i < returnSize; i++)
				printf("%s , ", result[i]);

		printf("\n");
	}
	return 0;
}