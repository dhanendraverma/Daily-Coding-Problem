/**************************************************************************************************************************************
This problem was asked by Facebook.
Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).
For example, given the string "([])[]({})", you should return true.
Given the string "([)]" or "((()", you should return false.
***************************************************************************************************************************************/


#include <iostream>
#include <stack>
using namespace std;

bool checkBalanceParantheses(string s){
	stack<int> st;
	for(auto ch:s){
		if(ch=='(' || ch=='{' || ch=='[')
			st.push(ch);
		else if(ch==']'){
			if(st.top()=='[')
				st.pop();
			else
				return false;
		}
		else if(ch=='}'){
			if(st.top()=='{')
				st.pop();
			else
				return false;
		}
		else if(ch==')'){
			if(st.top()=='(')
				st.pop();
			else
				return false;
		}
		
	}
	return st.empty();
}

int main() {
	// your code goes here
	cout<<checkBalanceParantheses("{()}[]")<<endl;
	cout<<checkBalanceParantheses("{()[}]")<<endl;
	return 0;
}
