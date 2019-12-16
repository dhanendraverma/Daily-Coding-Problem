/**************************************************************************************************************************************
This problem was asked by Microsoft.
Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string. For example, given the string
"abracadabra" and the pattern "abr", you should return [0, 7].
**************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void computeLPS(string pattern, vector<int>& lps){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<pattern.length()){
		if(pattern[i]==pattern[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len!=0)
				len = lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

vector<int> KMPSearch(string str, string pattern){
	int m = pattern.length();
	int n = str.length();
	vector<int> lps(m),ans;
	computeLPS(pattern,lps);
	int i=0,j=0;
	while(i<n){
		if(pattern[j]==str[i]){
			i++;
			j++;
		}
		if(j==m){
			ans.push_back(i-j);
			j = lps[j-1];
		}
		else if(i<n && pattern[j]!=str[i]){
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
	return ans;
}

int main() {
	string str = "abracadabra";
	string pattern = "abr";
	vector<int> indices = KMPSearch(str,pattern);
	for(auto i:indices)
		cout<<i<<" ";
	return 0;
}
