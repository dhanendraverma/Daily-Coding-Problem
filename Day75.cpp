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
int longestIncreasingSubsequenceDP(vector<int> arr){
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
//a great explanation here : https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int getCeilIdx(vector<int>& arr,int r,int key){
	int l = -1,mid;
	while(r-l>1){
		mid = l+(r-l)/2;
		if(arr[mid]>=key)
			r = mid;
		else
			l = mid;
	}
	return r;
}

int longestIncreasingSubsequence(vector<int> arr){
	int n = arr.size();
	vector<int> last_ele(n,0);
	int last_idx = 1;
	last_ele[0] = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>last_ele[last_idx-1])
			last_ele[last_idx++] = arr[i];
		else if(arr[i]<last_ele[0])
			last_ele[0] = arr[0];
		else{
			last_ele[getCeilIdx(arr,last_idx-1,arr[i])] = arr[i];
			cout<<getCeilIdx(arr,last_idx-1,arr[i])<<endl;
		}
		
	}
	return last_idx;
}

int main() {
	vector<int> arr = 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	cout<<longestIncreasingSubsequence(arr)<<endl;
	cout<<longestIncreasingSubsequenceDP(arr)<<endl;
	return 0;
}
