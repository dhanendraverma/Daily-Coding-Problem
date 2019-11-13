/***************************************************************************************************************************************
This problem was asked by Quora.
Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere in the word. If 
there is more than one palindrome of minimum length that can be made, return the lexicographically earliest one (the first one 
alphabetically).
For example, given the string "race", you should return "ecarace", since we can add three letters to it (which is the smallest amount 
to make a palindrome). There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes 
first alphabetically
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int min_palindrome(string str){
	int n = str.length();
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i=1;i<str.length();i++){
		for(int l=0,h=i;h<n;l++,h++){
			if(str[l]==str[h])
				dp[l][h] = dp[l+1][h-1];
			else{
				if(dp[l][h-1]==dp[l+1][h]){
					if(str[l]>str[h])
						dp[l][h] = 1+dp[l+1][h];
					else
						dp[l][h] = 1+dp[l][h-1];
				}
				else
					dp[l][h] = dp[l+1][h]<dp[l][h-1]?1+dp[l+1][h]:1+dp[l][h-1];
			}
		}
	}
	return dp[0][n-1];
}

int main() {
	// your code goes here
	cout<<min_palindrome("race")<<endl;
	cout<<min_palindrome("google")<<endl;
	return 0;
}
