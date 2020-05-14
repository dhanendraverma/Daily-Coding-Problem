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

bool backTrack(map<char,int>& cnt,vector<string>& nums,string& ans){
    bool done = true;
    for(auto c:cnt){
        if(c.second){
            done = false;
            break;
        }
    }
    if(done)
        return true;
    for(int i=0;i<10;i++){
        bool valid = true;
        for(auto c:nums[i]){
            if(!cnt[c])
                valid = false;
        }
        if(valid){
            for(auto c:nums[i])
                cnt[c]--;
            ans += to_string(i);
            if(backTrack(cnt,nums,ans))
                return true;
            ans.pop_back();
            for(auto c:nums[i])
                cnt[c]++;
        }
    }
    return false;
}

int anagramToInt(string str){
    vector<string> nums = {"zero","one","tow","three","four","five", "six", "seven", "eight", "nine"};
    map<char,int> numCnt;
    map<char,int> cnt;
    for(auto c:str)
        cnt[c]++;
    string ans = "";
    if(backTrack(cnt,nums,ans));
        sort(ans.begin(),ans.end());
        return stoi(ans);
    return -1;
}

int main() {
    string str = "niesevehrtfeev";
    cout<<anagramToInt(str)<<endl;
	return 0;
}
