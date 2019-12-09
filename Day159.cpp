/*****************************************************************************************************************************************
This problem was asked by Google.
Given a string, return the first recurring character in it, or null if there is no recurring character.
For example, given the string "acbbac", return "b". Given the string "abcdef", return null.
*****************************************************************************************************************************************/

#include <iostream>
#include <set>
using namespace std;

char findFirstRecurring(string str){
	set<char> s;
	for(auto c:str){
		if(s.find(c)!=s.end())
			return c;
		s.insert(c);
	}
	return NULL;
} 

int main() {
	string str = "abcdcef";
	cout<<findFirstRecurring(str)<<endl;
	return 0;
}
