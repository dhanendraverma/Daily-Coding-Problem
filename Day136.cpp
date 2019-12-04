/**************************************************************************************************************************************
This question was asked by Google.
Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.
For example, given the following matrix:
[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
Return 4.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxHist(vector<int> row){
	stack<int> s;
	int top_val;
	int max_area =0,area=0;
	int i=0;
	while(i<row.size()){
		if(s.empty() || row[i]>=row[s.top()])
			s.push(i++);
		else{
			top_val = row[s.top()];
			s.pop();
			area = top_val*(s.empty()?i:i-s.top()-1);
			max_area = max(area,max_area);
		}
	}
	while(!s.empty()){
		top_val = row[s.top()];
		s.pop();
		area = top_val*(s.empty()?i:i-s.top()-1);
		max_area = max(area,max_area);
	}
	return max_area;
}

int findMaxRect(vector<vector<int>> matrix){
	int ans = maxHist(matrix[0]);
	int n = matrix.size(), m = matrix[0].size();
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j])
				matrix[i][j] += matrix[i-1][j];
			ans = max(ans,maxHist(matrix[i]));
		}
	}
	return ans;
}


int main() {
	vector<vector<int>> matrix = { {0, 1, 1, 0}, 
								   {1, 1, 0, 1}, 
								   {1, 1, 1, 1}, 
								   {1, 1, 1, 0}};
	cout<<findMaxRect(matrix);
	return 0;
}
