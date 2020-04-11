/******************************************************************************************************************************
This problem was asked by Apple.
You are going on a road trip, and would like to create a suitable music playlist. The trip will require N songs, though you 
only have M songs downloaded, where M < N. A valid playlist should select each song at least once, and guarantee a buffer of
B songs between repeats.
Given N, M, and B, determine the number of valid playlists.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int validPlaylists(int N, int M, int B){
    vector<vector<int>> dp(N+1,vector<int>(M+1));
    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            //if we are playing jth song for the first time then (M-j+1) songs reamaining to choose
            dp[i][j] = dp[i-1][j-1]*(M-j+1);
            //if j songs have been used then only songs that were played k songs back can be used
            dp[i][j] += dp[i-1][j]*max(0,j-B);
            
        }
    }
    return dp[N][M];
}

int main() {
    int N = 3, M = 3, B = 1;
    cout<<validPlaylists(N,M,B)<<endl;
	return 0;
}
