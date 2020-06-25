/*******************************************************************************************************************************************************************
This problem was asked by Wayfair.
You are given a 2 x N board, and instructed to completely cover the board with the following shapes:
Dominoes, or 2 x 1 rectangles.
Trominoes, or L-shapes.
For example, if N = 4, here is one possible configuration, where A is a domino, and B and C are trominoes.
A B B C
A B C C
Given an integer N, determine in how many ways this task is possible.

Similar Questions : https://leetcode.com/problems/domino-and-tromino-tiling/
Explaination : https://www.youtube.com/watch?v=BlT6VCE6lGc
*******************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int no_of_arrangement(int N){
    vector<vector<int>> dp(N+1,vector<int>(2)); //of ways to fill board of length i when 1.It's fully filled 2.On corner is left corner
    T[0][0] = 1;
    T[1][0] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0]+ dp[i - 2][0] + dp[i - 1][1] 
        dp[i][1] = 2 * dp[i - 2][0] + dp[i - 1][1]
    }
    return dp[N][0;
}

int noOfArrangement(int N){
    vector<int> dp(N+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i=4;i<=N;i++)
        dp[i] = 2*dp[i-1]+dp[i-3];
    return dp[N];
}

int main() {
    int N = 4;
    cout<<noOfArrangement(N)<<endl;
	return 0;
}
