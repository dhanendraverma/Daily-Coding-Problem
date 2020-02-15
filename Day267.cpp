/*****************************************************************************************************************************
This problem was asked by Oracle.
You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board. The only pieces on the board 
are the black king and various white pieces. Given this matrix, determine whether the king is in check.
For details on how each piece moves, see here.
For example, given the following matrix:

...K....
........
.B......
......P.
.......R
..N.....
........
.....Q..

You should return True, since the bishop is attacking the king diagonally.
/****************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool isInCheck(vector<vector<char>> board){
	vector<pair<char,pair<int,int>>> pos;
	pair<int,int> kpos;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j] != '.'){
				if(board[i][j]=='K')
					kpos = {i,j};
				else
					pos.push_back({board[i][j],{i,j}});
			}
		}
	}
	for(auto piece:pos){
		//check for pawn attack
		if(piece.first=='P' && piece.second.first == kpos.first+1 &&
			(piece.second.second == kpos.second-1 ||piece.second.second == kpos.second+1))
				return true;
		//check for rook or queen attack
		if(piece.second.first == kpos.first || piece.second.second == kpos.second &&
			(piece.first == 'Q' || piece.first == 'R'))
				return true;
		int xdiff = piece.second.first-kpos.first;
		int ydiff = piece.second.second-kpos.second;
		//check for queen or bishop attack
		cout<<xdiff<<" "<<ydiff<<endl;
		if( xdiff == ydiff && piece.first == 'Q' || piece.first == 'B')
			return true;
		//check for knight attack
		if( xdiff*ydiff == 2)
			return true;
	}
	return false;
}

int main() {
	vector<vector<char>> board = {
		{'.', '.', '.', 'K', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', 'B', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', 'P', '.'},
		{'.', '.', '.', '.', '.', '.', '.', 'R'},
		{'.', '.', 'N', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', 'Q', '.', '.'}
	};
	cout<<isInCheck(board)<<endl;
	return 0;
}
