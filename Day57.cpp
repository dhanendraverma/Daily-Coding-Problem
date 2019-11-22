/**************************************************************************************************************************************
This problem was asked by Amazon.
Given a string s and an integer k, break up the string into multiple lines such that each line has a length of k or less.
You must break it up so that words don't break across lines. Each line has to have the maximum possible amount of words. 
If there's no way to break the text up, then return null.
You can assume that there are no spaces at the ends of the string and that there is exactly one space between each word.
For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, you should return:
["the quick", "brown fox", "jumps over", "the lazy", "dog"]. No string in the list has a length of more than 10.
**************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool word_break(string str,int k,vector<string>& ans){
	int cnt=0,prev=0,i=0;
	bool flag = false;
	while(true){
		while(cnt<=k){
			if((prev+cnt)>=str.length())
			{
				flag = true;
				break;
			}
			if(str[prev+cnt]==' ')
				i = cnt+prev;
			cnt++;
		}
		 if(prev==i+1 && cnt==11 )
			return false;
		if(flag){
			ans.push_back(str.substr(prev,cnt));
			break;
		}
		ans.push_back(str.substr(prev,i-prev));
		prev = i+1;
		cnt = 0;
	}
	return true;
}


int main() {
	string s = "the quick brown fox jumps over the lazy dog";
	int k =10;
	vector<string> ans;
	if(word_break(s,k,ans))
		for(auto i:ans)
			cout<<i<<endl;
	return 0;
}
