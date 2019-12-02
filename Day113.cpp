/*****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Google.
Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello"
Follow-up: given a mutable string representation, can you perform this operation in-place?
******************************************************************************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string str){
	int start = 0;
	for(int i=0;i<str.length();i++){
		if(str[i]==' '){
			reverse(str.begin()+start,str.begin()+i);
			start = i+1;
		}
	}
	reverse(str.begin()+start,str.end());
	reverse(str.begin(),str.end());
	return str;
}

int main() {
	string str = "i like programming very much";
	cout<<reverseWords(str);
	return 0;
}
