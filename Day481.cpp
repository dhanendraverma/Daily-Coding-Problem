/**************************************************************************************************************************************************************
This problem was asked by Jane Street.
Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.
The expression is given as a list of numbers and operands. For example: [5, 3, '+'] should return 5 + 3 = 8.
For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5, since it is equivalent to 
((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.
You can assume the given expression is always valid.
**************************************************************************************************************************************************************/

#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
using namespace std;
 
void applyOperand(string operand,stack<long>& exp){
	long val1 = exp.top();
	exp.pop();
	long val2 = exp.top();
	exp.pop();
	if(operand == "+")
		exp.push(val2+val1);
	else if(operand == "-")
		exp.push(val2-val1);
	else if(operand == "*")
		exp.push(val2*val1);
	else
		exp.push(val2/val1);
}
 
 
int evaluatePostfix(vector<string> postfix){
	stack<long> exp;
	for(int i=0;i<postfix.size();i++){
		char* p;
		long num = strtol(postfix[i].c_str(),&p,10);
		if(*p){
			applyOperand(postfix[i],exp);
		}
		else
			exp.push(num);
	}
	return exp.top();
}
 
int main() {
	vector<string> postfix = {"15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"};
	cout<<evaluatePostfix(postfix);
	return 0;
}
