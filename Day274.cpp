/****************************************************************************************************************************
This problem was asked by Facebook.
Given a string consisting of parentheses, single digits, and positive and negative signs, convert the string into a 
mathematical expression to obtain the answer.
Don't use eval or a similar built-in parser.
For example, given '-1 + (2 + 3)', you should return 4.
*****************************************************************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

int evaluateExp(string expr){
    stack<pair<int,char>> s;
    int temp=0,i=0,n=expr.length();
    while(i<expr.length()){
        if(expr[i]=='-'){
            i++;
            if(expr[i]=='('){
                s.push({temp,expr[i-1]});
                i++;
                temp = expr[i]-'0';
            }
            else
                temp -= expr[i]-'0';
        }
        else if(expr[i]=='+'){
            i++;
            if(expr[i]=='('){
                s.push({temp,expr[i-1]});
                i++;
                temp = expr[i]-'0';
            }
            else
                temp += expr[i]-'0';
        }
        else if(expr[i]==')'){
            pair<int,char> curr = s.top();
            s.pop();
            if(curr.second=='-')
                temp = curr.first-temp;
            else
                temp = curr.first+temp;
        }
        i++;
    }
    return temp;
}

int main() {
    string expr = "-1+(2-(3-2))";
    cout<<evaluateExp(expr)<<endl;
	return 0;
}
