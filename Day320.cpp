/******************************************************************************************************************************
This problem was asked by Amazon.
Given a string, find the length of the smallest window that contains every distinct character. Characters may appear more 
than once in the window.
For example, given "jiujitsu", you should return 5, corresponding to the final five letters.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string smallestWindow(string str){
    vector<int> count(26,0);
    int dist_cnt = 0;
    for(auto ch:str){
        count[ch-'a']++;
        if(count[ch-'a']==1)
            dist_cnt++;
    }
    fill(count.begin(), count.end(), 0);
    int min_len = INT_MAX, start = 0, start_idx = -1, cnt = 0;
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
        if(count[str[i]] == 1)
            cnt++;
        if(cnt == dist_cnt){
            while(count[str[start]]>1){
                count[str[start]]--;
                start++;
            }
        int win_len = i-start+1;
        if(win_len<min_len){
            win_len = min_len;
            start_idx = start;
        }
        }
    }
    return str.substr(start,min_len);
}

int main() {
    string str = "jiujitsu";
    cout<<smallestWindow(str)<<endl;
	return 0;
}
