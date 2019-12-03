/*****************************************************************************************************************************************
This question was asked by Zillow.
You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move
right or down, find the maximum number of coins you can collect by the bottom right corner.
For example, in this matrix
0 3 1 1
2 0 0 4
1 5 3 1
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;


int maxCoinsUtil(vector<vector<int>>& grid, int row, int col){
	if( row==grid.size()-1 && col==grid[0].size()-1)
		return grid[row][col];
	int right=0,down=0;
	if(col+1<grid[0].size()) 
		right = maxCoinsUtil(grid, row, col+1);
	if(row+1<grid.size()) 
		down = maxCoinsUtil(grid, row+1, col);
	
	return max(right,down)+grid[row][col];
}

int MaxCoins(vector<vector<int>>& grid){
	return maxCoinsUtil(grid, 0, 0);
}

int main() {
	vector<vector<int>> matrix = {{0, 3, 1, 1},
								 {2, 0, 0, 4},
								 {1, 5, 3, 1}};
	cout<<MaxCoins(matrix);
	return 0;
}
