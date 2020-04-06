/******************************************************************************************************************************
This problem was asked by Two Sigma.
A knight is placed on a given square on an 8 x 8 chessboard. It is then moved randomly several times, where each move is a 
standard knight move. If the knight jumps off the board at any point, however, it is not allowed to jump back on.
After k moves, what is the probability that the knight remains on the board?
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};
vector<int> dy = {2, 1, -1, -2, -2, -1, 1, 2};

double probTOSamePlace(int sx, int sy, int k){ 
    vector<vector<vector<double>>> dp(8,vector<vector<double>>(8,vector<double>(k+1)));
    for (int i=0;i<8;i++) 
        for (int j=0;j<8;j++) 
            dp[i][j][0] = 1; 

    for(int s=1;s<=k;s++){ 
        for(int x=0;x<8;x++){ 
            for(int y=0;y<8;y++){ 
                double p = 0.0; 
                for (int i=0;i<8;i++){ 
                    int nx = x+dx[i]; 
                    int ny = y+dy[i]; 
                    if (nx>=0 && nx<8 && ny>=0 && ny<8) 
                        p += dp[nx][ny][s-1] / 8.0; 
                } 
                dp[x][y][s] = p; 
            } 
        } 
    } 
    return dp[sx][sy][k]; 
} 

int main() {
    int k=3;
    cout<<probTOSamePlace(0,0,k)<<endl;
	return 0;
}
