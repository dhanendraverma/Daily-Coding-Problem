/*************************************************************************************************************************************
This problem was asked by Facebook.
Given a start word, an end word, and a dictionary of valid words, find the shortest transformation sequence from start to end such 
that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If there is no
possible transformation, return null. Each word in the dictionary have the same length as start and end and is lowercase.
For example, given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"}, return ["dog", "dot", "dat", "cat"].
Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"}, return null as there is no possible transformation 
from dog to cat.
**************************************************************************************************************************************/
#include <iostream>
#include <set>
#include <queue>
using namespace std; 

bool isAtDistOne(string A, string B) 
{ 
    bool edited = false;
	for (int i=0; i<A.length(); i++) 
	{ 
		if (A[i] != B[i]){
		    if(edited)
		        return false;
		    edited = true;
		 }
	} 
	return edited; 
} 


vector<string> shortestTrasformation(string start, string end, set<string> dict) 
{
    vector<string> chain;
	queue<pair<string,vector<string>>> q; 
	q.push({start,{start}}); 
	chain.push_back(start);
	while (!q.empty()) 
	{ 
		pair<string,vector<string>> curr = q.front(); 
		q.pop(); 
		for (auto itr=dict.begin(); itr!=dict.end(); itr++) 
		{ 
		    string temp = *itr; 
			if (isAtDistOne(curr.first, temp)) 
			{
			    vector<string> chain = curr.second;
			    chain.push_back(temp);
				q.push({temp,chain}); 
				dict.erase(temp); 
				if (temp == end)
				    return chain;
			} 
		} 
	} 
	return {}; 
} 

int main() 
{ 
	set<string> dict = {"dot", "dop", "dat", "cat"}; 
	string start = "dog"; 
	string end = "cat"; 
	vector<string> chain = shortestTrasformation(start,end,dict); 
	if(chain.size()){
	    for(auto s:chain)
	        cout<<s<<" ";
	}
	return 0; 
}
