/**************************************************************************************************************************************
This problem was asked by Coursera.
Given a 2D board of characters and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically 
neighboring. The same letter cell may not be used more than once.
For example, given the following board:
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

bool search(vector<vector<char>>& board, string word, int row, int col,int k){
	if(k==word.length()-1)
		return true;
	if(word[k]!=board[row][col])
		return false;
	int n_row,n_col;
	for(int i=0;i<4;i++){
		n_row = row+dir[i][0];
		n_col = col+dir[i][1];
		if(n_row<0 || n_row>=board.size() || n_col<0 || n_col>=board[n_row].size())
			continue;
		if(search(board,word,n_row,n_col,k+1))
			return true;
	}
	return false;
}

bool WordExist(vector<vector<char>>& board, string word){
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();i++){
			if(search(board,word,i,j,0))
				return true;
		}
	}
	return false;
}


int main() {
	vector<vector<char>> board = {{'A','B','C','E'},
								  {'S','F','C','S'},
								  {'A','D','E','E'}};
	cout<<WordExist(board,"ABCCED");
	// cout<<WordExist(board,"SEE");
	cout<<WordExist(board,"ABCB");
	return 0;
}
