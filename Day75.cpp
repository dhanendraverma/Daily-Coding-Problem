/*****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Microsoft.
Given an array of numbers, find the length of the longest increasing subsequence in the array. The subsequence does not necessarily have
to be contiguous.
For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], the longest increasing subsequence has length 6: 
it is 0, 2, 6, 9, 11, 15.
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//DP approach time - O(n^2) 
int longestIncreasingSubsequence(vector<int> arr){
	int n= arr.size(),ans=0;
	vector<int> dp(n);
	dp[0] = 1;
	for(int i=1;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && dp[j]+1>dp[i])
				dp[i] = dp[j]+1;
		}
		ans = max(ans,dp[i]);
	}
	return ans;
}

int main() {
	vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
	cout<<longestIncreasingSubsequence(arr)<<endl;
	return 0;
}
