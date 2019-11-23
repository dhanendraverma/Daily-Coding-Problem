/**************************************************************************************************************************************
This problem was asked by Google.
A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.
Given N, write a function to return the number of knight's tours on an N by N chessboard.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> row_pos = {2, 1, -1, -2, -2, -1,  1,  2};
vector<int> col_pos = { 1, 2,  2,  1, -1, -2, -2, -1};

bool is_safe(vector<vector<int>> moves,int row,int col,int n){
	return (row>=0 && row<n && col>=0 && col<0 && moves[row][col]==-1);
}
 
int is_knight_tour(vector<vector<int>>& moves,int row,int col,int steps,int n){
	
	if(steps==n*n)
		return 1;
	int temp_cnt = 0;
	int next_row,next_col;
	for(int i=0;i<8;i++){
		next_row = row+row_pos[i];
		next_col = col+col_pos[i];
		if(is_safe(moves,next_row,next_col,n)){
			moves[next_row][next_col] = steps;
			if(is_knight_tour(moves,next_row,next_col,steps+1,n))
				temp_cnt++;
			moves[next_row][next_col] = -1;
		}
	}
	return temp_cnt;
}



int knight_tours(int n){
	int tours = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		vector<vector<int>> moves(n,vector<int>(n,-1));
		moves[i][j] = 0;
		tours += is_knight_tour(moves,0,0,1,n);
		}
	}
	return tours;
}


int main() {
	int n = 5;
	cout<<knight_tours(n);
	return 0;
}
