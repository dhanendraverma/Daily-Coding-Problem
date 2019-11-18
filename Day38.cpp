/**************************************************************************************************************************************
This problem was asked by Microsoft.
You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where N queens can 
be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.
***************************************************************************************************************************************/
#include<bits/stdc++.h> 

using namespace std;

bool isSafe(vector<vector<int>> board, int row, int col, int N) 
{ 
	int i, j; 
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 
	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 

	for (i=row, j=col; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 
	return true; 
} 


bool solveNQUtil(vector<vector<int>> &board, int col,int *ans,int N) 
{ 
	if (col == N) 
	{ 
      *ans = *ans+1;
		return true; 
	} 
	bool res = false; 
	for (int i = 0; i < N; i++) 
	{ 
		if ( isSafe(board, i, col,N) ) 
		{ 
			board[i][col] = 1; 
			res = solveNQUtil(board, col + 1,ans, N) || res; 
			board[i][col] = 0; 
		} 
	} 
	return res; 
} 


void solveNQ(int N) 
{ 
	vector<vector<int>> board(N,vector<int>(N,0)); 
	int ans = 0;
	solveNQUtil(board, 0,&ans,N);
	cout<<ans<<endl;
	return ; 
} 


int main() 
{
	int N;
	cin>>N;
	solveNQ(N); 
	return 0; 
} 
