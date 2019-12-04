/****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Facebook.
Given an array of numbers representing the stock prices of a company in chronological order and an integer k, return the maximum profit
you can make from k buys and sells. You must buy the stock before you can sell it, and you must sell the stock before you can buy it again.
For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> prices, int k){
	vector<vector<int>> dp(k+1,vector<int>(prices.size()+1,0));
	for(int i=1;i<=k;i++){
		int trackDiff = INT_MIN;
		for(int j=1;j<=prices.size();j++){
			trackDiff = max(trackDiff, dp[i-1][j-1]-prices[j-1]);
			dp[i][j] = max(dp[i][j-1], prices[j]+trackDiff);
		}
	}
	return dp[k][prices.size()-1];
}

int main() {
	vector<int> prices = {5, 2, 4, 0, 1};
	int k = 2;
	cout<<maxProfit(prices,k)<<endl;
	return 0;
}
