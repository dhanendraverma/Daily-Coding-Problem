/****************************************************************************************************************************************
This problem was asked by Facebook.
Given an N by N matrix, rotate it by 90 degrees clockwise.
For example, given the following matrix:
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
you should return:
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
Follow-up: What if you couldn't use any extra space?
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void rotateMat(vector<vector<int>>& matrix){
	int n = matrix.size(), m = matrix[0].size();
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size()-i;j++){
			// cout<<n-1-j<<" "<<m-1-i<<"|"<<i<<" "<<j<<endl;;
			swap(matrix[i][j],matrix[n-1-j][m-1-i]);
		}
	}
	for(int j=0;j<matrix[0].size();j++){
		for(int i=0;i<matrix.size()/2;i++)
			swap(matrix[i][j],matrix[m-i-1][j]);
	}
}


int main() {
	vector<vector<int>> matrix = {{1, 2, 3},
								{4, 5, 6},
								{7, 8, 9}};
	rotateMat(matrix);
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
