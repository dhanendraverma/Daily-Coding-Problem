/****************************************************************************************************************************************
This problem was asked by Yelp.
Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent. 
You can assume each valid number in the mapping is a single digit.
For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return 
[“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generatAllPossible(string num_string, int str_len, string curr_str){
	if(str_len==num_string.length()){
		cout<<curr_str<<endl;
		return;
	}

		for(auto word:mapping[num_string[str_len]-'0']){
			if(word)
				generatAllPossible(num_string,str_len+1,curr_str+word);			
		}
}

int main() {
	string num_string = "234";
	generatAllPossible(num_string,0,"");
	return 0;
}
