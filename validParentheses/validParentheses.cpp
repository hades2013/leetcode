#include <iostream>
#include <string.h>
#include <stack> 

using namespace std;

class Solution {  
public:  
    bool isValid(string s) {  
        stack<char> stk;  
        int len = s.length();  
        for (int i = 0; i < len; i++) {  
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {  
                stk.push(s[i]);  
            } else {  
                if (stk.empty())  
                    return false;  
                if (stk.top() == '(' && s[i] == ')')  
                    stk.pop();  
                else if (stk.top() == '[' && s[i] == ']')  
                    stk.pop();  
                else if (stk.top() == '{' && s[i] == '}')   
                    stk.pop();  
                else  
                    return false;  
            }  
        }  
        return stk.empty();  
    }  
};  


int main(int argc, char const *argv[])
{
	Solution A;
	bool result;
	string str = "(1123, rsf[9[0]8}]sfds(44))";
	result = A.isValid(str);
	cout<<"isValid result: "<<result<<endl;
	return 0;
}