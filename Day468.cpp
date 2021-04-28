/****************************************************************************************************************************************************************
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
****************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat){
	int n = mat.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i; j++){
			swap(mat[i][j], mat[n-1-j][n-1-i]);
		}
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n/2;i++)
			swap(mat[i][j], mat[n-i-1][j]);
	}
}


int main() {
	vector<vector<int>> mat { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	rotateMatrix(mat);
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat.size(); j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
