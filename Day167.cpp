/**************************************************************************************************************************************
This problem was asked by Airbnb.
Given a list of words, find all pairs of unique indices such that the concatenation of the two words is a palindrome.
For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)].
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX 256

class TrieNode{
	public:
	vector<TrieNode*> children;
	vector<int> pos;
	int id;
	bool isLeaf;
	TrieNode(){
		this->isLeaf = false;
		this->children = vector<TrieNode*>(MAX,NULL);
	}
};

bool isPalindrome(string str,int start,int end){
	while(start<end){
		if(str[start]!=str[end])
			return false;
		start++;
		end--;
	}
	return true;
}

void search(string word, set<pair<int,int>>& ret, TrieNode* root, int id){
	for(int i=0;i<word.length();i++){
		if(root->id>=0 && root->id!=id && isPalindrome(word,i,word.length()-1))
			ret.insert({id,root->id});
		if(!root->children[word[i]])
			return;
		root = root->children[word[i]];
	}
	for(auto i:root->pos){
		if(i!=id)
			ret.insert({id,i});
	}
}


void insert(TrieNode* root,string word, int id){
	for(int i=word.length()-1;i>=0;i--){
		if(!root->children[word[i]])
			root->children[word[i]] = new TrieNode();
		if(isPalindrome(word,0,i))
			(root->pos).push_back(id);
		root = root->children[word[i]];
	}
	root->id = id;
	(root->pos).push_back(id);
	root->isLeaf = true;
}

set<pair<int,int>> findPalinPairs(vector<string> words){
	TrieNode* root = new TrieNode();
	for(int i=0;i<words.size();i++)
		insert(root,words[i],i);
	set<pair<int,int>> ret;
	for(int i=0;i<words.size();i++)
		search(words[i],ret,root,i);
	return ret;
}

int main() {
	vector<string> words = {"code", "edoc", "da", "d"};
	set<pair<int,int>> ans = findPalinPairs(words);
	for(auto i:ans){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}
