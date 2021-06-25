/*******************************************************************************************************************************************************
This problem was asked by Facebook.
Boggle is a game played on a 4 x 4 grid of letters. The goal is to find as many words as possible that can be formed by a sequence of adjacent letters
in the grid, using each cell at most once. Given a game board and a dictionary of valid words, implement a Boggle solver.
*******************************************************************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

bool valid(int x, int y, int m, int n, vector<vector<bool>>& vis) {
  return ( x>=0 && x<n && y>=0 && y<m && vis[x][y]==false );
}
 
bool check(string s,int id,int i,int j, int m, int n, vector<vector<bool>>& visited, vector<vector<char>>& mat) {

    if(id>=s.size())
        return 1;

    for(int k=0;k<8;k++) {
        int u = i+dx[k];
        int v = j+dy[k];
        if(valid(u, v, m, n, visited) && mat[u][v]==s[id]) {
            visited[u][v] = 1;
            if(check(s, id+1, u, v, m, n, visited, mat))
                return 1;
            visited[u][v] = 0;
        }
    }
    return 0;
}

int main() {
  vector<string> words = {"CAT", "GMAT", "JEE", "IIT", "NEET"};
  vector<vector<char>> board = {{ 'C', 'I', 'E', 'N' },
                                { 'T', 'A', 'K', 'E' },
                                { 'Q', 'S', 'M', 'T' },
                                { 'T', 'G', 'O', 'I' }};
  int m = board.size(), n = board[0].size();
  for(auto word:words){
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        if(board[i][j] == word[0] && check(word, 1, i, j, m, n, visited, board))
          cout<<word<<endl;
      }
    }
  }
}
