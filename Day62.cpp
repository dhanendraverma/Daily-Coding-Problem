/*****************************************************************************************************************************************
This problem was asked by Facebook.
There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left corner and 
getting to the bottom-right corner. You can only move right or down.
For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:
Right, then down
Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int countWays(int n, int m){
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int i=0 ;i<=n; i++)
		dp[i][1] = 1;
	for(int j=0; j<=m; j++)
		dp[1][j] = 1;
	for(int i=2; i<=n; i++){
		for(int j=2; j<=m; j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
	}
	
	// for(auto row:dp){
	// 	for(auto ele:row)
	// 		cout<<ele<<" ";
	// 	cout<<endl;
	// }
	return dp[n][m];
}

int main() {
	int n = 5;
	int m = 5;
	cout<<countWays(n,m)<<endl;
	return 0;
}



long long find_ways(int m,int n){
	if(m==1 || n==1)
		return 1;
	return find_ways(m-1,n)+find_ways(m,n-1);
}

int main() {
	int n=5,m=5;
	cout<<find_ways(n,m)<<endl;
	cout<<countWays(n,m)<<endl;
	return 0;
}
