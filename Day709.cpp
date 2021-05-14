/**************************************************************************************************************************************
This problem was asked by Slack.
You are given an N by M matrix of 0s and 1s. Starting from the top left corner, how many ways are there to reach the bottom right
corner?
You can only move right and down. 0 represents an empty space while 1 represents a wall you cannot walk through.
For example, given the following matrix:
[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]
Return two, as there are only two ways to get to the bottom right:
Right, down, down, right
Down, right, down, right
The top left corner and bottom right corner will always be 0.
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void findWaysRecur(vector<vector<int>>& matrix,int n,int m, int& ans, int row, int col){
	if(row>=n || col>=m || matrix[row][col]==1)
		return;
	if(row==n-1 && col==m-1){
		ans++;
		return;
	}
	findWaysRecur(matrix,n,m,ans,row+1,col);
	findWaysRecur(matrix,n,m,ans,row,col+1);
}

int findWays(vector<vector<int>>& matrix){
	int n = matrix.size(), m = matrix[0].size(), ans=0;
	findWaysRecur(matrix,n,m,ans,0,0);
	return ans;
}

int main() {
	vector<vector<int>> matrix = {{0, 0, 1},
								 {0, 0, 1},
								 {1, 0, 0}};
	cout<<findWays(matrix)<<endl;
	return 0;
}
