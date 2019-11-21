/**************************************************************************************************************************************
This problem was asked by Amazon.
Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length, return any one.
For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas" is "anana".
***************************************************************************************************************************************/


#include <iostream>
using namespace std;

string LPS(string str){
	int n = str.length();
	bool T[n][n] = {0};
	for(int i=0;i<n;i++)
		T[i][i] = true;
	int max_len = 1;
	int start = 0;
	for(int i=0;i<n-1;i++){
		if(str[i]==str[i+1])
		{
			T[i][i+1] = true;
			max_len = 2;
			start = i;
		}
	}
	for(int l=3;l<=n;l++){
		for(int i=0;i<n-l+1;i++){
			int j = i+l-1;
			if(T[i+1][j-1] && str[i]==str[j]){
				T[i][j] = true;
				if(l>max_len){
					start = i;
					max_len = l;
				}
			}
		}
	}
	return str.substr(start,max_len);
}


int main() {
	string str = "aabcdcb"; 
	cout<<LPS(str)<<endl; //bcdcb
	cout<<LPS("bananas")<<endl; //anana
	cout<<LPS("forgeeksskeegfor")<<endl; //geeksskeeg
	return 0;
}
