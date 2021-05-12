/************************************************************************************************************************************************************
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
*************************************************************************************************************************************************************/

#include <iostream>
#include <queue>

using namespace std; 
 
vector<vector<int>> dir = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
  
class Node{
	public:
		pair<int,int> cord;
		int dist;
		Node(pair<int,int> cord, int dist){
			this->cord = cord;
			this->dist = dist;
		}
};
 
bool isValid(int row, int col,int ROW, int COL){ 
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL); 
} 

int minSteps(vector<vector<char>> matrix, pair<int,int> src, pair<int,int> dest){
	
	if ( matrix[src.first][src.second] == 't' || matrix[dest.first][dest.second] != 'f') 
        return -1; 
    
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col,false));
    visited[src.first][src.second] = true; 
    queue<Node> q; 
    Node src_node = Node(src,0);
    q.push(src_node); 
    
    while (!q.empty()){ 
        Node curr = q.front(); 
        pair<int,int> curr_pt = curr.cord; 
        if (curr_pt==dest) 
            return curr.dist; 
        q.pop();
        for (int i = 0; i < 4; i++) 
        { 
            int nxt_row = curr_pt.first + dir[0][i]; 
            int nxt_col = curr_pt.second + dir[1][i]; 
            if( isValid(nxt_row, nxt_col, row, col) && matrix[nxt_row][nxt_col] == 'f' && !visited[nxt_row][nxt_col] ) 
            { 
                visited[nxt_row][nxt_col] = true; 
                Node Adjcell = Node({nxt_row, nxt_col},curr.dist + 1); 
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
  
    int dist = minSteps(matrix, source, dest); 
  
    if (dist != -1) 
        cout << "Shortest Path is " << dist ; 
    else
        cout << "Shortest Path doesn't exist"; 
  
    return 0; 
} 
