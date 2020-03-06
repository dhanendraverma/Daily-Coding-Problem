/*****************************************************************************************************************************
This problem was asked by Spotify.
Write a function, throw_dice(N, faces, total), that determines how many ways it is possible to throw N dice with some number 
of faces each to get a specific total.
For example, throw_dice(3, 6, 7) should equal 15.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int numOfWays(int N, int faces, int total){
	vector<vector<int>> dp(N+1,vector<int>(total+1,0));
	for(int i=1;i<=faces && i<=total;i++)
		dp[1][i] = 1;
	for(int i=2;i<=N;i++){
		for(int j=1;j<=total;j++){
			for(int k=1;k<=faces && k<j;k++)
				dp[i][j] += dp[i-1][j-k];
		}
	}
	return dp[N][total];
}


int main() {
	int N = 3, faces = 6, total = 7;
	cout<<numOfWays(N,faces,total)<<endl;
	return 0;
}
