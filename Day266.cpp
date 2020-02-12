/*****************************************************************************************************************************
This problem was asked by Pivotal.
A step word is formed by taking a given word, adding a letter, and anagramming the result. For example, starting with the 
word "APPLE", you can add an "A" and anagram to get "APPEAL".
Given a dictionary of words and an input word, create a function that returns all valid step words.
/*****************************************************************************************************************************/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void findStepWords(set<string> dict, string word){
	for(int i=0;i<26;i++){
		string new_word = word + char(i+'a');
		sort(new_word.begin(),new_word.end());
		do{
			if(dict.find(new_word)!=dict.end())
				cout<<new_word<<endl;
		}while(next_permutation(new_word.begin(),new_word.end()));
	}
}

int main() {
	set<string> dict = {"appeal","apple","bpplea","patple","alppey"};
	string word = "apple";
	findStepWords(dict,word);
	return 0;
}
