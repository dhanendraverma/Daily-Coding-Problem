/***************************************************************************************************************************************************************
This problem was asked by Square.
In front of you is a row of N coins, with values v1, v1, ..., vn.
You are asked to play the following game. You and an opponent take turns choosing either the first or last coin from the row, removing it from the row, and r
eceiving the value of the coin.
Write a program that returns the maximum amount of money you can win with certainty, if you move first, assuming your opponent plays optimally.
***************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int maxAmtMoney(vector<int>& coins){
	int n = coins.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for(int d=0; d<n; d++){
		for(int i=0; i<n-d; i++){
			int j = i+d;
			int x = ((i+2)<=j) ? dp[i+2][j] : 0;
			int y = ((i+1)<=j-1) ? dp[i+1][j-1] : 0;
			int z = ((i)<=j-2) ? dp[i][j-2] : 0;
			dp[i][j] = max(coins[i] + min(x,y), coins[j] + min(y,z));
		}
	}
	return dp[0][n-1];
}


int main() {
	vector<int> coins = {8, 15, 3, 7 };
	cout<<maxAmtMoney(coins)<<endl;
	return 0;
}
