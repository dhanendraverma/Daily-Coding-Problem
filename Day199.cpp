/*****************************************************************************************************************************************
This problem was asked by Facebook.
Given a string of parentheses, find the balanced string that can be produced from it using the minimum number of insertions and deletions.
If there are multiple solutions, return any of them. 
For example, given "(()", you could return "(())". Given "))()(", you could return "()()()()".
*****************************************************************************************************************************************/

#include <iostream>
using namespace std;

string MinEdits(string p){
	int open=0;
	string bp="";
	for(char c:p){
		if(c=='(')
			open++;
		else if(c==')'){
			if(open==0)
				bp += "(";
			else
				open--;
		}
		bp += c;
	}
	while(open--)
		bp += ")";
	return bp;
}

int main() {
	string p = "(()";
	cout<<MinEdits(p)<<endl;
	return 0;
}
