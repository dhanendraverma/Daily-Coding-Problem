/************************************************************************************************************************************************************
This problem was asked by Amazon.
Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s 
that are neighboring whose perimeter is surrounded by water.
For example, this matrix has 4 islands.
1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
*************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ngbr = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}}; 

bool is_safe(int i, int j, int n, int m, vector<vector<bool>>& visited, vector<vector<int>>& mat){
	return (i>-1) && (i<n) && (j>-1) && (j<m) && (!visited[i][j] && mat[i][j]);
}

void dfs(vector<vector<int>> mat,vector<vector<bool>>& visited, int i, int j){
	visited[i][j] = true;
	int n = mat.size();
	int m = mat[0].size();
	int nxt_i,nxt_j;
	for(int k=0;k<8;k++){
		nxt_i = i+ngbr[k][0];
		nxt_j = j+ngbr[k][1];
		if(is_safe(nxt_i,nxt_j,n,m,visited,mat) && !visited[nxt_i][nxt_j])
			dfs(mat,visited,nxt_i,nxt_j);
	}
}

int count_islands(vector<vector<int>> mat){
	int n = mat.size();
	int m = mat[0].size(),count=0;
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j] && !visited[i][j]){
				dfs(mat,visited,i,j);
				count++;
			}
		}
	}
	return count;
}

int main() {
	vector<vector<int>> mat = {{1, 0, 0, 0, 0},
		                       {0, 0, 1, 1, 0},
                               {0, 1, 1, 0, 0},
                               {0, 0, 0, 0, 0},
                               {1, 1, 0, 0, 1},
                               {1, 1, 0, 0, 1}};
	cout<<count_islands(mat);
	return 0;
}
