/****************************************************************************************************************************************
This problem was asked by Facebook.
Given a positive integer n, find the smallest number of squared integers which sum to n.
For example, given n = 13, return 2 since 13 = 3^2 + 2^2 = 9 + 4.
Given n = 27, return 3 since 27 = 3^2 + 3^2 + 3^2 = 9 + 9 + 9.
*****************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

int MinsqNum(int n){
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i=4;i<=n;i++){
		dp[i] = i;
		for(int j=1;j*j<=i;j++){
			dp[i] = min(dp[i],dp[i-j*j]+1);
		}
	}
	return dp[n];
}

int main() {
	int n = 13;
	cout<<MinsqNum(n)<<endl;
	return 0;
}
