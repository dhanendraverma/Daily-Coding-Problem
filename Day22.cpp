/**************************************************************************************************************************************
This problem was asked by Microsoft.
Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more 
than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.
For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", 
you should return ['the', 'quick', 'brown', 'fox'].
Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond",
return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
***************************************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

string breakWordDP(string word, set<string> dict){
	vector<vector<int> > T(word.length(),vector<int> (word.length(),-1));
	for(int l = 1; l <= word.length(); l++){
		for(int i=0; i < word.length() -l + 1 ; i++){
			int j = i + l-1;
			string str = word.substr(i,l);
			if(dict.find(str)!=dict.end()){
				T[i][j] = i;
				continue;
			}
			for(int k=i+1; k <= j; k++){
				if(T[i][k-1] != -1 && T[k][j] != -1){
					T[i][j] = k;
					break;
				}
			}
		}
	}
    if(T[0][word.length()-1] == -1)
        return NULL;
    string ans = "";
    int i = 0; int j = word.length() -1;
    while(i < j){
		int k = T[i][j];
		if(i == k){
			ans += word.substr(i, j+1-i);
			break;
		}
		ans += word.substr(i,k-i) + " ";
		i = k;
	}
    return ans;
}



int main() {
	set<string> dictionary;
	dictionary.insert("bed");
	dictionary.insert("bath");
	dictionary.insert("bedbath");
	dictionary.insert("and");
	dictionary.insert("beyond");
	string str = "bedbathandbeyond";
	cout<<breakWordDP(str, dictionary);
	return 0;
}
