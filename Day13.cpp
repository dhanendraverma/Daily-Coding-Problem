/*************************************************************************************************************************************
This problem was asked by Amazon.
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
**************************************************************************************************************************************/

#include <bits/stdc++.h>
#define MAX_CHARS 256 
using namespace std; 

bool isValid(vector<int> count, int k) 
{ 
	int unique = 0; 
	for (int i=0; i<MAX_CHARS; i++) 
		if (count[i] > 0) 
			unique++; 

	return (k >= unique); 
} 

void kUniques(string s, int k) 
{
    int n = s.length(); 
	int u = 0; 
	vector<int> count(MAX_CHARS,0); 
	
	for (int i=0; i<n; i++) 
	{ 
		if (count[s[i]-'a']==0) 
			u++; 
		count[s[i]-'a']++; 
	} 

	if (u < k) 
	{ 
		cout << "Not enough unique characters"; 
		return; 
	} 

	int curr_start = 0, curr_end = 0; 

	int max_window_size = 1, max_window_start = 0; 
	fill(count.begin(), count.end(), 0);

	count[s[0]-'a']++;

	for (int i=1; i<n; i++) 
	{ 
	
		count[s[i]-'a']++; 
		curr_end++; 

		while (!isValid(count, k)) 
		{ 
			count[s[curr_start]-'a']--; 
			curr_start++; 
		} 

	
		if (curr_end-curr_start+1 > max_window_size) 
		{ 
			max_window_size = curr_end-curr_start+1; 
			max_window_start = curr_start; 
		} 
	} 

	cout << "Max sustring is : "
		<< s.substr(max_window_start, max_window_size) 
		<< " with length " << max_window_size << endl; 
} 


int main() 
{ 
	string s; 
	int k; 
	cin>>s>>k;
	kUniques(s, k); 
	return 0; 
} 
