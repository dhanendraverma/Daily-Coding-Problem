/*****************************************************************************************************************************
This problem was asked by Yelp.
You are given an array of integers, where each element represents the maximum number of steps that can be jumped going 
forward from that element. Write a function to return the minimum number of jumps you must take in order to get from the
start to the end of the array.
For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the optimal solution involves jumping from 6 to 5,
and then from 5 to 9.
******************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumpsToEnd(vector<int> jumps){
	int n = jumps.size();
	vector<int> dp(n,INT_MAX);
	if(n==0 || jumps[0]<=0)
		return INT_MAX;
	dp[0] = 0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=jumps[i]&&(i+j)<n;j++){
			dp[i+j] = min(dp[i+j],dp[i]+1);
		}
	}
	return dp[n-1];
}

int main() {
	vector<int> jumps = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
	cout<<minJumpsToEnd(jumps)<<endl;
	return 0;
}
