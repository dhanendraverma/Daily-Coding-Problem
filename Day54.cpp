/*************************************************************************************************************************************
This problem was asked by Dropbox.
Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. The objective is to fill the grid with the constraint that every row, column, and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.
Implement an efficient sudoku solver.
**************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool usedInBox(vector<vector<int>> board,int boxrow, int boxcol, int num){
	for(int row=0;row<3;row++){
		for(int col=0;col<3;col++)
			if(board[boxrow+row][boxcol+col]==num)
				return true;
	return false;
	}
}

bool usedInRow(vector<vector<int>> board,int row, int num){
	for(int col=0;col<9;col++)
		if(board[row][col]==num)
			return true;
	return false;
}

bool usedInCol(vector<vector<int>> board,int col, int num){
	for(int row=0;row<9;row++)
		if(board[row][col]=num)
			return true;
	return false;
}

bool isSafe(vector<vector<int>>& board,int row, int col, int num){
	return board[row][col]==0 && !usedInRow(board,row,num) && !usedInCol(board,col,num) && !usedInBox(board,row-row%3,col-col%3,num);
}

bool leftUnfilled(vector<vector<int>> board,int& row, int& col){
	for (row = 0; row<9; row++)  
		for (col = 0; col<9; col++)  
		    if (board[row][col] == 0)  
		        return true;  
	return false;  
}

bool solveSudoku(vector<vector<int>>& board){
	int row,col;
	if(!leftUnfilled(board,row,col))
		return true;
	for(int num=1;num<=9;num++){
		if(isSafe(board,row,col,num)){
			board[row][col] = num;
			if(solveSudoku(board))
				return true;
			board[row][col] = 0;
		}
	}
	return false;
}

void printSol(vector<vector<int>> board)  
{  
    for (int row=0; row<9; row++)  
    {  
    	for (int col = 0; col<9; col++)  
    		cout << board[row][col] << " ";  
	    cout << endl; 
    	
    }  
} 

int main() {
	vector<vector<int>> board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
			                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
			                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
			                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
			                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
			                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
			                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
			                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
			                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
    if (solveSudoku(board) == true)  
        printSol(board);  
    else
        cout << "No solution exists"; 
	return 0;
}
