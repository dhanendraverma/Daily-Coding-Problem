/***********************************************************************************************************************************************************
This problem was asked by Airbnb.
Given a list of words, find all pairs of unique indices such that the concatenation of the two words is a palindrome.
For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)].
***********************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string a){
	int l = 0, r = a.length()-1;
	while(l<r){
		if( a[l] != a[r])
			return false;
		l++;
		r--;
	}
	return true;
}

vector<pair<int,int>> palindromicPairs(vector<string> lst){
	vector<pair<int,int>> ans;
	for(int i=0;i<lst.size();i++){
		for(int j=i+1;j<lst.size();j++){
			if(isPalindrome(lst[i]+lst[j]))
				ans.push_back({i,j});
		}
	}
	return ans;
}

int main() {
	vector<string> lst = {"code", "edoc", "da", "d"};
	vector<pair<int,int>> pairs = palindromicPairs(lst);
	for(auto p: pairs)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;
}
