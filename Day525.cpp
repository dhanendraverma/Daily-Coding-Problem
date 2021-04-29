/**********************************************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Amazon.
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.
For example, given the following matrix:
[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:
1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12
**********************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void printSpiralOrder(vector<vector<int>> mat){
	int curr_row = 0, curr_col = 0, end_col = mat[0].size(), end_row = mat.size();
	while( curr_row < end_row && curr_col< end_col ){
		for(int i=curr_col; i<end_col; i++)
			cout<<mat[curr_row][i]<<" ";
		curr_row++;
		for(int i=curr_row; i<end_row; i++)
			cout<<mat[i][end_col-1]<<" ";
		end_col--;
		if(curr_row < end_row){
			for(int i=end_col-1; i>=curr_col; i--)
				cout<<mat[end_row-1][i]<<" ";
			end_row--;
		}
		if(curr_col < end_col){
			for(int i=end_row-1; i>=curr_row; i--)
				cout<<mat[i][curr_col]<<" ";
			curr_col++;
		}
	}
} 



int main() {
	vector<vector<int>> mat = {{1,  2,  3,  4,  5},
							   {6,  7,  8,  9,  10},
							   {11, 12, 13, 14, 15},
							   {16, 17, 18, 19, 20}};
    printSpiralOrder(mat);
	return 0;
}
