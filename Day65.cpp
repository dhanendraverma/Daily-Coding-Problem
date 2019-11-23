/*****************************************************************************************************************************************
This problem was asked by Amazon.
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.
For example, given the following matrix:
[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:
1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void print_spiral_order(vector<vector<int>> mat){
	int row_end = mat.size(),col_end = mat[0].size();
	int row = 0,col=0;
	while(col<col_end && row<row_end){
		for(int i=col;i<col_end;i++)
			cout<<mat[row][i]<<" ";
		row++;
		for(int i=row;i<row_end;i++)
			cout<<mat[i][col_end-1]<<" ";
		col_end--;
		if(row<row_end){
			for(int i=col_end-1;i>=col;i--)
				cout<<mat[row_end-1][i]<<" ";
			row_end--;
		}
		if(col<col_end){
			for(int i=row_end-1;i>=row;i--)
				cout<<mat[i][col]<<" ";
			col++;
		}
	}
}

int main() {
	vector<vector<int>> mat = {{1,  2,  3,  4,  5},
							   {6,  7,  8,  9,  10},
							   {11, 12, 13, 14, 15},
							   {16, 17, 18, 19, 20}};
    print_spiral_order(mat);
	return 0;
}
