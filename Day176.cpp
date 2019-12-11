/*****************************************************************************************************************************************
This problem was asked by Bloomberg.
Determine whether there exists a one-to-one character mapping from one string s1 to another s2.
For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.
Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
******************************************************************************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

bool possible_mapping(string s1, string s2){
	vector<int> mp(26,-1);
	if(s1.length()!=s2.length())
		return false;
	for(int i=0;i<s1.length();i++){
		if(mp[s1[i]-'a']==-1)
			mp[s1[i]-'a'] = s2[i]-'a';
		else if(mp[s1[i]-'a']!=s2[i]-'a')
			return false;
	}
	return true;
}


int main() {
	string s1 = "foo";
	string s2 = "bar";
	cout<<possible_mapping(s1,s2)<<endl;
}
