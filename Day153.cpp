/***************************************************************************************************************************************
Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in a string.
For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return 1 because 
there's only one word "cat" in between the two words.
***************************************************************************************************************************************/

#include <iostream>
#include <sstream>

using namespace std;

int countDist(string text, string start, string end){
	int count = 0, mn_cnt=text.length();
	bool flag = false;
	stringstream ss(text);
	string word;
	while(ss>>word){
		if(word==start){
			flag = true;
			count = 0;
		}
		else if(word==end){
			mn_cnt = min(mn_cnt,count);
			count=0;
			flag = false;
		}
		else if(flag){
			count++;
		}
	}
	return mn_cnt;
}

int main() {
	string str = "dog cat hello cat dog dog hello cat world";
	string word1 = "hello";
	string word2 = "world";
	cout<<countDist(str,word1,word2)<<endl;
	return 0;
}
