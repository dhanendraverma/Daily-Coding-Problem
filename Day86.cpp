/*****************************************************************************************************************************************
This problem was asked by Google.
Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid 
(i.e. each open parenthesis is eventually closed).
For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

int min_removals(string s){
	int open=0,close=0;
	for(auto i:s){
		if(i=='(')
			open++;
		else{
			if(open)
				open--;
			else
				close++;
		}
	}
	return open+close;
}

int main() {
	string s=")(";
	cout<<min_removals(s);
	return 0;
}
