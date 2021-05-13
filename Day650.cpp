/*****************************************************************************************************************************************
This problem was asked by Google.
Let A be an N by M matrix in which every row and every column is sorted.
Given i1, j1, i2, and j2, compute the number of elements of M smaller than M[i1, j1] and larger than M[i2, j2].
For example, given the following matrix:
[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]
And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15 numbers in the matrix smaller than 6 or greater than 23.
******************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SmallerGreater(vector<vector<int>> matrix, int i1, int j1, int i2, int j2){
	int n = matrix.size(), m = matrix[0].size();
	int row=0;
	int smaller=0, greater=0;
	while(row<n && matrix[row][0]<matrix[i1][j1]){
		auto itr = lower_bound(matrix[row].begin(), matrix[row].end(), matrix[i1][j1]);
		smaller += (itr - matrix[row].begin());
		row++;
	}
	row=n-1;
	while(row>-1 && matrix[row][m-1]>matrix[i2][j2]){
		auto itr = upper_bound(matrix[row].begin(), matrix[row].end(), matrix[i2][j2]);
		greater += (matrix[row].end()-itr);
		row--;
	}
	return smaller+greater;
}


int main() {
	vector<vector<int>> matrix = {{1, 3, 7, 10, 15, 20},
								 {2, 6, 9, 14, 22, 25},
								 {3, 8, 10, 15, 25, 30},
								 {10, 11, 12, 23, 30, 35},
								 {20, 25, 30, 35, 40, 45}};
	int i1=1,j1=1,i2=3,j2=3;
	cout<<SmallerGreater(matrix,i1,j1,i2,j2);
	return 0;
}
