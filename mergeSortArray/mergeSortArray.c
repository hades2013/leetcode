#include <stdio.h>
#include <stdlib.h>

void mergeB(int *nums1, int m, int *nums2, int n)
{
	while(m > 0 && n > 0){
		if(nums1[m -1] > nums2[n-1]){
			nums1[m+n-1] = nums1[m -1]; 
			m--; 
		}
		else{
			nums1[m+n-1] = nums2[n-1]; 
			n--; 
		}
	}
	while(n > 0){
		nums1[m+n -1] = nums2[n-1];
		n--; 
	}
	while(m > 0){
		nums1[m+n -1] = nums1[m -1]; 
		m--;
	}

}

void mergeA(int *nums1, int m, int *nums2, int n)
{
	int *tmp; 
	tmp = (int *)malloc(sizeof(int)* (m+n));
	int i =0, j=0; 
	int t = 0; 

	while(i < m && j < n){
		if(nums1[i] < nums2[j])
			tmp[t++] = nums1[i++];
		else 
			tmp[t++] = nums2[j++]; 
	}
	int k; 
	if(i == m){
		for(k = j; k < n; k++)
			tmp[t++] = nums2[k]; 
	}
	else if(j == n){
		for(k = i; k < m; k++)
			tmp[t++] = nums1[k];
	}
	for (k =0; k < m+n; k++)
		nums1[k] = tmp[k];
	free(tmp);
}
int main(int argc, char const *argv[])
{
	int nums1[]= {1,2,3,4,5,6,7,8,9,10};
	int nums2[]= {5,6,7,8,9,10,11,12,13};
	int len1 = sizeof(nums1)/sizeof(int);
	int len2 = sizeof(nums2)/sizeof(int);
	mergeB(nums1, len1, nums2, len2);
	int i=0; 
	for(i=0; i < len2+len1; i++){
		printf("%d->", nums1[i]);
	}
	printf("\n");
	return 0;
}