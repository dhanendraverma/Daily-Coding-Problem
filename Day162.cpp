/**************************************************************************************************************************************
This problem was asked by Square.
Given a list of words, return the shortest unique prefix of each word. For example, given the list:
dog
cat
apple
apricot
fish
Return the list:
d
c
app
apr
f
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX 256

class TrieNode{
	public:
	int frequency;
	TrieNode *children[MAX];
	TrieNode(){
		this->frequency = 1;
		for(int i=0;i<256;i++)
			this->children[i] = NULL;
	}
};

void insert(string word,TrieNode* root){
	for(int i=0;i<word.length();i++){
		if(root->children[word[i]])
			(root->children[word[i]]->frequency)++;
		else
			root->children[word[i]] = new TrieNode();
		root = root->children[word[i]];
	}
}

string findPrehelper(TrieNode* root, string word){
	string prefix = "";
	for(int i=0;i<word.length();i++){
		prefix += word[i];
		if(root->children[word[i]]->frequency==1)
			return prefix;
		root = root->children[word[i]];
	}
	return prefix;
}

vector<string> findPrefixes(vector<string> words){
	TrieNode* root = new TrieNode();
	root->frequency = 0;
	for(auto word:words)
		insert(word,root);
	vector<string> prefixes(words.size());
	for(int i=0;i<words.size();i++)
		prefixes[i] = findPrehelper(root,words[i]);
	return prefixes;
}

int main() {
	vector<string> words = {"dog","cat","apple","apricot","fish"};
	vector<string> prefixes = findPrefixes(words);
	for(auto pre:prefixes)
		cout<<pre<<endl;
	return 0;
}
