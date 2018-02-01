#include <iostream> 
#include <vector>

using namespace std; 

int maxSubArray(const vector<int> &arr, int &begin , int &end)
{
	int maxSum = 0;
	int currSum = 0; 
	int newbegin = 0; 
	for(int i; i < arr.size(); ++i){
		currSum+=arr[i];
		if(currSum > maxSum){
			maxSum=currSum;
			begin = newbegin;
			end =i;
		}
		if(currSum<0){
			currSum=0; 
			newbegin=i+1; 
		}
	}
	return maxSum;
}
int main(int argc, char const *argv[])
{
	int len;
	cout<<"input array length:"<<endl;
	cin>>len;
	cout<<"input an integer vector:"<<endl;
	vector<int> arr; 
	int a; 
	for(int i =0; i< len; ++i){
		cin>>a; 
		arr.push_back(a); 
	}
	int begin, end; 
	cout<<maxSubArray(arr, begin, end)<<endl;
	for(int i=begin; i< end; ++i)
		cout<<arr[i]<<" "; 
	cout<<endl;
	return 0;
}