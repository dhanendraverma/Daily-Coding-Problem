/******************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Flexport.
Given a string s, rearrange the characters so that any two adjacent characters are not the same. If this is not possible,
return null.
For example, if s = yyz then return yzy. If s = yyy then return null.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

bool isDiffAdj(string str){
    int count[26] = {0};
    int n = str.length();
    for(auto c:str){
        count[c-'a']++;
        if(count[c-'a']>(n+1)/2)
            return false;
    }
    return true;
}


int main() {
    string str = "yzy";
    cout<<isDiffAdj(str)<<endl;
	return 0;
}
