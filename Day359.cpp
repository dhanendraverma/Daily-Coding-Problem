/******************************************************************************************************************************
This problem was asked by Slack.
You are given a string formed by concatenating several words corresponding to the integers zero through nine and then 
anagramming.For example, the input could be 'niesevehrtfeev', which is an anagram of 'threefiveseven'. Note that there can 
be multiple instances of each integer.
Given this string, return the original integers in sorted order. In the example above, this would be 357.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool getIntRec(map<char, int>& count, map<int, vector<pair<char,int>>>nums, string& ans){
	bool done  = true;
	for(auto char_cnt:count){
		if(char_cnt.second){
			done = false;
			break;
		}
	}
	
	if(done)
		return true;
		
	for(auto num:nums){
		
		bool can_use = true;
		
		for(auto ch_cnt:num.second){
			if(count[ch_cnt.first]<ch_cnt.second){
				can_use = false;
				break;
			}
		}
		
		if(can_use){
			ans += to_string(num.first);
			for(auto ch_cnt:num.second)
				count[ch_cnt.first] -= ch_cnt.second;
			if(getIntRec(count, nums, ans))
				return true;
			ans.pop_back();
			for(auto ch_cnt:num.second)
				count[ch_cnt.first] += ch_cnt.second;
		}
		
	}
	return false;
}

int anagramToInt(string str){
    map<int , vector<pair<char, int>>> nums;
    nums[0] = {{'z',1}, {'e',1}, {'r',1}, {'o',1}};
    nums[1] = {{'o',1}, {'n',1}, {'e',1}};
    nums[2] = {{'t',1}, {'o',1}, {'w',1}};
    nums[3] = {{'t',1}, {'h',1}, {'r',1}, {'e',2}};
    nums[4] = {{'f',1}, {'o',1}, {'u',1}, {'r',1}};
    nums[5] = {{'f',1}, {'i',1}, {'v',1}, {'e',1}};
    nums[6] = {{'s',1}, {'i',1}, {'x',1}};
    nums[7] = {{'s',1}, {'e',2}, {'v',1}, {'n',1}};
    nums[8] = {{'e',1}, {'i',1}, {'g',1}, {'h',1}, {'t',1}};
    nums[9] = {{'n',2}, {'i',1}, {'e',1}};
    map<char,int> count;
    for(auto c:str)
        count[c]++;
    string ans = "";
    if(getIntRec(count, nums, ans));
        sort(ans.begin(), ans.end());
        return stoi(ans);
    return -1;
}

int main() {
	string str = "niesevehrtfeev";
    cout<<anagramToInt(str)<<endl;
	return 0;
}
