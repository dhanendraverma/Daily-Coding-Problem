/*****************************************************************************************************************************************
This problem was asked by Goldman Sachs.
You are given N identical eggs and access to a building with k floors. Your task is to find the lowest floor that will cause an egg to
break, if dropped from that floor. Once an egg breaks, it cannot be dropped again. If an egg breaks when dropped from the xth floor, you
can assume it will also break when dropped from any floor greater than x.
Write an algorithm that finds the minimum number of trial drops it will take, in the worst case, to identify this floor.
For example, if N = 1 and k = 5, we will need to try dropping the egg at every floor, beginning with the first, until we reach the fifth 
floor, so our solution will be 5.
******************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minTrials(int f, int e){
	vector<vector<int>> dp(e+1,vector<int>(f+1));
	for(int i=0;i<=f;i++)
		dp[1][i]=i;
	for(int i=2;i<=e;i++){
		for(int j=1;j<=f;j++){
			dp[i][j] = INT_MAX;
			for(int k=1;k<=j;k++)
				dp[i][j] = min(dp[i][j],1+max(dp[i-1][j-1],dp[i][j-k]));
		}
	}
	return dp[e][f];
}

int main() {
	int floors = 38;
	int eggs = 2;
	cout<<minTrials(floors,eggs)<<endl;
	return 0;
}
