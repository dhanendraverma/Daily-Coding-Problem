/**************************************************************************************************************************************
This problem was asked by Google.
Given a word W and a string S, find all starting indices in S which are anagrams of W.
For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.
**************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

bool compareMaps(vector<int>& s_map, vector<int>& word_map){
	for(int i=0;i<256;i++)
		if(s_map[i]!=word_map[i])
			return false;
	return true;
}

vector<int> findAnagramIndices(string word, string s) 
{
	vector<int> ans;
	if(word.length()>s.length())
		return ans;
	int word_len = word.length();
	vector<int> word_map(256,0), s_map(256,0); 
	for (int i=0; i<word_len; i++) 
	{ 
		word_map[word[i]]++; 
		s_map[s[i]]++; 
	} 
	for (int i=word_len; i<s.length(); i++) 
	{ 
		if (compareMaps(word_map, s_map)) 
			ans.push_back(i - word_len); 
		s_map[s[i]]++; 
		s_map[s[i-word_len]]--; 
	} 
	if (compareMaps(word_map, s_map)) 
		ans.push_back(s.length()-word_len);
	return ans;
} 


int main() {
	string word = "ABCD";
	string s = "BACDGABCDA";
	vector<int> ans = findAnagramIndices(word,s);
	for(auto i:ans)
		cout<<i<<" ";
	return 0;
}
