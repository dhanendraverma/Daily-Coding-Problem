/******************************************************************************************************************************
This problem was asked by Google.
You are given a set of synonyms, such as (big, large) and (eat, consume). Using this set, determine if two sentences with the
same number of words are equivalent.
For example, the following two sentences are equivalent:
"He wants to eat food."
"He wants to consume food."
Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c): consider the case of (coach, bus) and 
(coach, teacher).
Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?
******************************************************************************************************************************/

#include <iostream>
#include <map>
#include <sstream>
using namespace std;

bool areSame(string str1, string str2,map<string,string>& syn){
    string word1,word2;
    stringstream ss1(str1), ss2(str2);
    while(ss1>>word1 && ss2>>word2){
        if(word1 != word2 && syn[word1]!=word2)
            return false;
        // cout<<word1<<" "<<word2<<endl;
    }
    return true;
}

int main() {
    map<string,string> syn;
    syn["eat"] = "consume";
    syn["big"] = "large";
    syn["complete"] = "accomplish";
    string sentence1 = "He wants to eat food";
    string sentence2 = "He wants to consume food";
    cout<<areSame(sentence1,sentence2,syn)<<endl;
	return 0;
}
