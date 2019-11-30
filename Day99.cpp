/*****************************************************************************************************************************************
This problem was asked by Microsoft.
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
*****************************************************************************************************************************************/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int longestConsequence(vector<int> arr){
	set<int> nums;
	for(auto i:arr)
		nums.insert(i);
	int ans=0,curr=0;
	for(auto i:arr){
		if(nums.find(i-1)==nums.end()){
			while(nums.find(i) != nums.end()){
				curr++;
				i++;
			}
			ans = max(ans,curr);
			curr =0;
		}
	}
	return ans;
}




int main() {
	vector<int> arr = {100, 4, 200, 1, 3, 2};
	cout<<longestConsequence(arr);
	return 0;
}
