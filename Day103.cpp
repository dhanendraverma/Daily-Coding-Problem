/**************************************************************************************************************************************
This problem was asked by Square.
Given a string and a set of characters, return the shortest substring containing all the characters in the set.
For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
If there is no substring containing all the characters in the set, return null.
**************************************************************************************************************************************/
#include<bits/stdc++.h> 
using namespace std; 

string shortestSub(string str, vector<char> char_set) 
{ 
	if (char_set.size()>str.length()) 
		return ""; 
	vector<int> char_map(256,0); 
	vector<int> str_map(256,0); 
	for (int i=0; i<char_set.size(); i++) 
		char_map[char_set[i]]++; 
	int start = 0, start_idx = -1, shortest_win = INT_MAX, count = 0; 
	for (int i=0; i<str.length(); i++) 
	{ 
		str_map[str[i]]++; 
		if (char_map[str[i]] != 0 && 
			str_map[str[i]] <= char_map[str[i]] ) 
			count++; 
		if (count == char_set.size()) 
		{ 
			while ( str_map[str[start]] > char_map[str[start]] || char_map[str[start]] == 0) 
			{ 
				if (str_map[str[start]] > char_map[str[start]]) 
					str_map[str[start]]--; 
				start++; 
			} 
			int win_len = i-start+1; 
			if (shortest_win > win_len) 
			{ 
				shortest_win = win_len; 
				start_idx = start; 
			} 
		} 
	} 
	if (start_idx == -1) 
		return ""; 
	return str.substr(start_idx, shortest_win); 
} 

 
int main() 
{ 
	string str = "figehaeci";
	vector<char> char_set = {'a', 'e', 'i'}; 
	cout<<shortestSub(str, char_set); 
	return 0; 
} 
