/**************************************************************************************************************************************
This problem was asked by Google.
Given a string which we can delete at most k, return whether you can make a palindrome.
For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

bool canMakePalindrome(string str, int k){
	int i=0,j=str.length()-1;
	while(i<j){
		if(str[i]!=str[j]){
			if(str[i]==str[j-1]){
				k--;
				j--;
			}
			else if(str[i+1]==str[j]){
				k--;
				i++;
			}
			else{
				k -= 2;
				i++;
				j--;
			}
		}
		else{
			i++;
			j--;
		}
		if(k<0)
			return false;
	}
	return true;
}

int main() {
	string str = "waterrfetawx";
	int k = 5;
	cout<<canMakePalindrome(str,k);
	return 0;
}
