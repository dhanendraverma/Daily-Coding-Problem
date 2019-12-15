/**************************************************************************************************************************************
This problem was asked by Google.
You are given an array of arrays of integers, where each array corresponds to a row in a triangle of numbers. For example,
[[1], [2, 3], [1, 5, 1]] represents the triangle:
  1
 2 3
1 5 1
We define a path in the triangle to start at the top and go down one row at a time to an adjacent value, eventually ending with an
entry on the bottom row. For example, 1 -> 3 -> 5. The weight of the path is the sum of the entries.
Write a program that returns the weight of the maximum weight path.
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxWtPath(vector<vector<int>> triangle){
	int n = triangle.size();
	vector<vector<int>> path1(n),path2(n);
	for(int i=0;i<n;i++)
		path2[i].push_back(triangle[n-1][i]);
	for(int i=triangle.size()-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(triangle[i+1][j]>triangle[i+1][j+1]){
				path1[j] = path2[j];
				path1[j].push_back(triangle[i][j]);
				triangle[i][j] += triangle[i+1][j];
			}
			else{
				path1[j] = path2[j+1];
				path1[j].push_back(triangle[i][j]);
				triangle[i][j] += triangle[i+1][j+1];
			}
			// for(auto k:path1[j])
			// 	cout<<k<<" ";
			// cout<<endl;
		}
		path2.swap(path1);
	}
	reverse(path2[0].begin(),path2[0].end());
	return path2[0];
}


int main() {
	vector<vector<int>> triangle = {{1},{2,3},{1,5,1}};
	vector<int> path = maxWtPath(triangle);
	for(auto i:path)
		cout<<i<<" ";
	return 0;
}
