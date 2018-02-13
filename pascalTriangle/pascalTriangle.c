#include <stdio.h>
#include <stdlib.h>


int** generateB(int numRows, int** columnSizes) {
	int* returnSize;
    if(!columnSizes) return 0;
    if(!returnSize||numRows==0) return 0;
    int **returnArray=(int **)malloc(numRows*sizeof(int *));
    *columnSizes=malloc(sizeof(int)*numRows);
    
    *returnSize=0;
    int i=0;
    int j=0;
    for(i=0;i<numRows;i++){
           returnArray[i]=(int *)malloc(sizeof(int)*(i+1));
          //columnSizes[i]=(int *)malloc(sizeof(int)*(1));
          (*columnSizes)[i]=i+1;
            for(j=0;j<i+1;j++)
            {
                if(j==0) 
                {
                    returnArray[i][j]=1;
                }else if(j==i)
                {
                    returnArray[i][j]=1;
                }else{
                    returnArray[i][j]=returnArray[i-1][j]+returnArray[i-1][j-1];
                }
                
            }
            (*returnSize)++;
            //columnSizes[i][0]=(int)(sizeof(returnArray[i]));
        }
    //columnSizes=columnSizesArray;
    return returnArray;
}
int **generateA(int numRows, int **columnSizes)
{
	int i =0, j=0; 
	if(numRows == 0)
		return 0; 
	int **returnArray = (int **)malloc(sizeof(int *)*numRows);
	*columnSizes = (int *)malloc(sizeof(int)*numRows);

	for(i=0; i< numRows; i++){
		(*columnSizes)[i] = i+1; 
		returnArray[i]= (int *)malloc(sizeof(int)*(i+1));
		for(j =0; j < i+1; j++){
			if((0 ==j) || (i == j))
				returnArray[i][j] = 1;
			else
				returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
		}
	}
	return returnArray; 
}

int main(int argc, char const *argv[])
{
	int numRows; 
	int *columnSizes = NULL;
	int **returnArray = NULL;
	int i,j; 
	printf("input your numRows: ");
	scanf("%d", &numRows); 
	returnArray = generateB(numRows, &columnSizes);
	for(i =0; i < numRows; i++){
		for(j = 0 ; j < i+1 ; j++)
			printf(" %d  ", returnArray[i][j]);
		printf("\n");
	}

	return 0;
}