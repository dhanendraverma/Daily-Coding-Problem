/***********************************************************************************************************************************************************
This problem was asked by Airbnb.
Given a list of words, find all pairs of unique indices such that the concatenation of the two words is a palindrome.
For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)].
***********************************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX 256

class TrieNode{
	public:
	vector<TrieNode*> children;
	vector<int> ppos;
	int idx;
	bool isLeaf;
	TrieNode(){
		this->isLeaf = false;
		this->children = vector<TrieNode*>(MAX,NULL);
	}
};

bool isPalindrome(string str, int start, int end){
	while(start < end){
		if( str[start] != str[end] )
			return false;
		start++;
		end--;
	}
	return true;
}

void search(string word, set<pair<int,int>>& ans, TrieNode* root, int idx){
	for(int i=0; i<word.length(); i++){
		if(root->idx>=0 && root->idx != idx && isPalindrome(word, i, word.length()-1))
			ans.insert({idx, root->idx});
		if(!root->children[word[i]])
			return;
		root = root->children[word[i]];
	}
	for(auto i:root->ppos){
		if(i!=idx)
			ans.insert({idx, i});
	}
}


void insert(TrieNode* root, string word, int idx){
	for(int i=word.length()-1; i>=0; i--){
		if(!root->children[word[i]])
			root->children[word[i]] = new TrieNode();
		if(isPalindrome(word, 0, i))
			(root->ppos).push_back(idx);
		root = root->children[word[i]];
	}
	root->idx = idx;
	(root->ppos).push_back(idx);
	root->isLeaf = true;
}

set<pair<int,int>> findPalinPairs(vector<string> words){
	TrieNode* root = new TrieNode();
	for(int i=0; i<words.size(); i++)
		insert(root, words[i], i);
	
	set<pair<int,int>> pairs;
	for(int i=0;i<words.size();i++)
		search(words[i], pairs, root, i);
	return pairs;
}

bool isPalindromic(string a){
	int l = 0, r = a.length()-1;
	while(l<r){
		if( a[l] != a[r])
			return false;
		l++;
		r--;
	}
	return true;
}

vector<pair<int,int>> palindromicPairs(vector<string> lst){
	vector<pair<int,int>> ans;
	for(int i=0;i<lst.size();i++){
		for(int j=i+1;j<lst.size();j++){
			if(isPalindromic(lst[i]+lst[j]))
				ans.push_back({i,j});
		}
	}
	return ans;
}

int main() {
	vector<string> lst = {"code", "edoc", "da", "d"};
	vector<pair<int,int>> pairs = palindromicPairs(lst);
	for(auto p: pairs)
		cout<<p.first<<" "<<p.second<<endl;
	pairs = findPalinPairs(lst);
	for(auto p: pairs)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;
}
