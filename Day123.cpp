/**************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by LinkedIn.
Given a string, return whether it represents a number. Here are the different kinds of numbers:
"10", a positive integer
"-10", a negative integer
"10.1", a positive real number
"-10.1", a negative real number
"1e5", a number in scientific notation
And here are examples of non-numbers:
"a"
"x 1"
"a -2"
"-"
**************************************************************************************************************************************/
#include <iostream>
using namespace std;

bool isValidNum(string str){
	int i=0;
	bool dotSeen = false, eSeen = false;
	if(str[0]=='-' || str[0]=='+') i++;
	while(i<str.length()){
		cout<<i<<endl;
		if(str[i]<'0' || str[i]>'9'){
			if(str[i]=='.'){
				if(dotSeen)
					return false;
				dotSeen = true;
				i++;
				continue;
			}
			if(str[i]=='e'){
				if(eSeen)
					return false;
				eSeen = true;
				dotSeen = false;
				i++;
				continue;
			}
			return false;
		}
		i++;
	}
	return true;
}

int main() {
	string str = "+3.3.e55.3";
	cout<<isValidNum(str);
	return 0;
}
