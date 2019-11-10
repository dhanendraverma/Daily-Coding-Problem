/***************************************************************************************************************************************
This problem was asked by Facebook.
Implement regular expression matching with the following special characters:
. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the 
regular expression.For example, given the regular expression "ra." and the string "ray", your function should return true. The same
regular expression on the string "raymond" should return false.Given the regular expression ".*at" and the string "chat", 
your function should return true. The same regular expression on the string "chats" should return false.
***************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

bool matchRegex(string text, string pattern) {
	vector<vector<bool>> T(text.length() + 1, vector<bool>(pattern.length() + 1));

        T[0][0] = true;
        //Deals with patterns like a* or a*b* or a*b*c*
        for (int i = 1; i < T[0].size(); i++) {
            if (pattern[i-1] == '*') {
                T[0][i] = T[0][i - 2];
            }
        }

        for (int i = 1; i < T.size(); i++) {
            for (int j = 1; j < T[0].size(); j++) {
                if (pattern[j - 1] == '.' || pattern[j - 1] == text[i - 1]) {
                    T[i][j] = T[i-1][j-1];
                } else if (pattern[j - 1] == '*')  {
                    T[i][j] = T[i][j - 2];
                    if (pattern[j-2] == '.' || pattern[j - 2] == text[i - 1]) {
                        T[i][j] = T[i][j] | T[i - 1][j];
                    }
                } else {
                    T[i][j] = false;
                }
            }
        }
        return T[text.size()][pattern.size()];
    }

int main() {
	// your code goes here
	cout<<matchRegex("ray","ra.")<<endl; //true
	cout<<matchRegex("raymond","ra.")<<endl;  //false
	cout<<matchRegex("raymond","ra.*")<<endl; //true
	return 0;
}
