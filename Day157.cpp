/****************************************************************************************************************************************
This problem was asked by Amazon.
Given a string, determine whether any permutation of it is a palindrome.
For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome. daily should return false,
since there's no rearrangement that can form a palindrome.
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

bool canPalindrome(string  str){
	vector<int> cnt(256,0);
	for(int i=0;i<str.length();i++){
		cnt[str[i]]++;
	}
	int odd_cnt=0;
	for(int i=0;i<256;i++){
		if(cnt[str[i]]&1)
			odd_cnt++;
		if(odd_cnt>1)
			return false;
	}
	return true;
}

int main() {
	string str= "carrace";
	cout<<canPalindrome(str)<<endl;
	return 0;
}
