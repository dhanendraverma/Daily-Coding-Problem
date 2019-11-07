/****************************************************************************************************************************************
This problem was asked by Google.
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. 
Each False boolean represents a tile you can walk on.
Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end
coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. 
You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:
[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, 
since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
*****************************************************************************************************************************************/

#include <bits/stdc++.h> 
using namespace std; 
  
struct queueNode 
{ 
    pair<int,int> pt;  
    int dist; 
}; 
 
bool isValid(int row, int col,int ROW, int COL) 
{ 
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL); 
} 

int BFS(vector<vector<char> > mat, pair<int,int> src, pair<int,int> dest) 
{
	int rowNum[] = {-1, 0, 0, 1}; 
	int colNum[] = {0, -1, 1, 0}; 
	if (mat[src.first][src.second]=='t' || !mat[dest.first][dest.second]=='t') 
        return -1; 
	
	bool visited[mat.size()][mat.size()]; 
    memset(visited, false, sizeof visited); 
    visited[src.first][src.second] = true; 
    queue<queueNode> q; 
    queueNode s = {src, 0}; 
    q.push(s); 
    while (!q.empty()) 
    { 
        queueNode curr = q.front(); 
        pair<int,int> curr_pt = curr.pt; 
        if (curr_pt==dest) 
            return curr.dist; 
        q.pop(); 
        for (int i = 0; i < 4; i++) 
        { 
            int row = curr_pt.first + rowNum[i]; 
            int col = curr_pt.second + colNum[i]; 
            if (isValid(row, col,mat.size(),mat[0].size()) && mat[row][col]=='f' &&  
               !visited[row][col]) 
            { 
                visited[row][col] = true; 
                queueNode Adjcell = { {row, col}, 
                                      curr.dist + 1 }; 
                q.push(Adjcell); 
            } 
        } 
    } 
    return -1; 
} 
  
 
int main() 
{ 
    vector<vector<char> > matrix = {{'f', 'f', 'f', 'f'},
									{'t', 't', 'f', 't'},
									{'f', 'f', 'f', 'f'},
									{'f', 'f', 'f', 'f'}};
								  
    pair<int,int> source = {3, 0}; 
    pair<int,int> dest = {0, 0}; 
  
    int dist = BFS(matrix, source, dest); 
  
    if (dist != INT_MAX) 
        cout << "Shortest Path is " << dist ; 
    else
        cout << "Shortest Path doesn't exist"; 
  
    return 0; 
} 
