/**************************************************************************************************************************************
This problem was asked by Microsoft.
Given an array of positive integers, divide the array into two subsets such that the difference between the sum of the subsets is as 
small as possible.
For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20}, which has a difference of 5, which is the smallest 
possible difference.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinDiff(vector<int> nums){
	int s=0, n=nums.size();
	for(auto i:nums)
		s += i;
	vector<vector<bool>> dp(n+1,vector<bool>(s+1));
	for(int i=0;i<=n;i++)
		dp[i][0] = true;
	for(int i=1;i<=s;i++)
		dp[0][i] = false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			dp[i][j] = dp[i-1][j];
			if(nums[i-1]<=j)
				dp[i][j] = dp[i][j] | dp[i-1][j-nums[i-1]];
			
		}
	}
	int min_diff = INT_MAX;
	for(int j=s/2;j>=0;j--){
		if(dp[n][j]==true){
			min_diff = s-2*j;
			break;
		}
	}
	return min_diff;
}

int main() {
	vector<int> nums = {5, 10, 15, 20, 25};
	cout<<findMinDiff(nums)<<endl;
	return 0;
}
