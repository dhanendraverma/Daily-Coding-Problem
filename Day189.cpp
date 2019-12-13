/****************************************************************************************************************************************
This problem was asked by Google.
Given an array of elements, return the length of the longest subarray where all its elements are distinct.
For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <int> longestSubArr(vector<int> arr){
	map<int,int> mp;
	pair<int,int> ans;
	int start = 0,i;
	mp[arr[0]] = 0;
	int mx_len = 1;
	for(i=1;i<arr.size();i++){
		if(mp.find(arr[i])!=mp.end()){
			if(i-start>mx_len){
				ans = {start,i};
				mx_len = (i-start);
				start = mp[arr[i]]+1;
			}
		}
		mp[arr[i]] = i;
	}
	if(i-start>mx_len)
		ans = {start,i};
	return vector<int>(arr.begin()+ans.first, arr.begin()+ans.second);

}

int main() {
	vector<int> arr = {5, 1, 3, 5,11,12,13,14,15,15,2, 3, 4, 1,27,28,29,30,31,32,33};
	vector<int> subarr = longestSubArr(arr);
	for(auto i:subarr)
		cout<<i<<" ";
	return 0;
} 
