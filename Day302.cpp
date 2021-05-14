/**************************************************************************************************************************************************************
his problem was asked by Uber.
You are given a 2-d matrix where each cell consists of either /, \, or an empty space. Write an algorithm that determines into how many regions the slashes
divide the space.
For example, suppose the input for a three-by-six grid is the following:

\    /
 \  /
  \/
Considering the edges of the matrix as boundaries, this divides the grid into three triangles, so you should return 3.
**************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int>>& g, int i, int j){
    if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j])
        return;
    g[i][j] = 1;
    dfs(g, i+1, j);
    dfs(g, i-1, j);
    dfs(g, i, j+1);
    dfs(g, i, j-1);
}
    
int regionsBySlashes(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> g(n*3, vector<int>(m*3, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '\\')
               g[i*3][j*3] = g[i*3+1][j*3+1] = g[i*3+2][j*3+2] = 1;
            else if(grid[i][j] == '/')
                g[i*3][j*3+2] = g[i*3+1][j*3+1] = g[i*3+2][j*3] = 1;
        }
    }
    int regions = 0;
    for(int i=0; i<n*3; i++){
        for(int j=0; j<m*3; j++){
            if(g[i][j] == 0){
                dfs(g, i, j);
                regions++;
            }
        }
    }
    return regions;
}


int main() {
	vector<vector<char>> matrix = {{' ','/'},
		{'/',' '}};
	cout<<regionsBySlashes(matrix)<<endl;
	matrix = {{'\\', ' ', ' ', ' ', ' ', '/'},
	          {' ', '\\', ' ', ' ', '/', ' '},
	          {' ', ' ', '\\','/', ' ', ' '}};
	cout<<regionsBySlashes(matrix)<<endl;
	return 0;
}
