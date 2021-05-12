/***********************************************************************************************************************************************************
This problem was asked by Palantir.
A typical American-style crossword puzzle grid is an N x N matrix with black and white squares, which obeys the following rules:
Every white square must be part of an "across" word and a "down" word.
No word can be fewer than three letters long.
Every white square must be reachable from every other white square.
The grid is rotationally symmetric (for example, the colors of the top left and bottom right squares must match).
Write a program to determine whether a given matrix qualifies as a crossword grid.
********************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool RotationalSymmetric(vector<vector<char>>& grid){
    for(int i=0;i<grid.size();i++){
        int br = grid.size()-i-1;
        int cr = grid[i].size()-i-1;
        int c = grid[i].size()-1;
		for(int j=0;j<cr;j++){
		    if(grid[i][j]!=grid[br][c-j])
				return false;
		}
	}
	return true;
}

void dfs(vector<vector<char>>& grid,int i,int j){
    grid[i][j] = 'd';
    if(i>0 && grid[i-1][j]=='w')
        dfs(grid,i-1,j);
    if(i<grid.size()-1 && grid[i+1][j]=='w')
        dfs(grid,i+1,j);
    if(j>0 && grid[i][j-1]=='w')
        dfs(grid,i,j-1);
    if(j<grid[i].size()-1 && grid[i][j+1]=='w')
        dfs(grid,i,j+1);
}

bool checkReachable(vector<vector<char>> grid){
    bool flag = false;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='w'){
                if(!flag){
                    flag = true;
                    dfs(grid,i,j);
                }
                else
                    return false;
            }
        }
    }
    return true;
}

bool checkWordLen(vector<vector<char>>& grid){
    int len = 0;
    int row = grid.size(), col = grid[0].size();
    
    // check for across words
    int curr_row = 0, curr_col;
    for(curr_row=0; curr_row<row; curr_row++){
    	curr_col = 0;
    	while(curr_col<col){
    		if(grid[curr_row][curr_col] == 'b'){
    			curr_col++;
    			continue;
    		}
    		len = 0;
    		while( curr_col<col && grid[curr_row][curr_col]=='w'){
    			curr_col++;
    			len++;
    		}
    		if(len<3)
    			return false;
    	}
    }
    
    // check vertical words
    for(curr_col=0; curr_col<col; curr_col++){
    	curr_row = 0;
    	while(curr_row < row){
    		if(grid[curr_row][curr_col] == 'b'){
    			curr_row++;
    			continue;
    		}
    		len = 0;
    		while( curr_row < row && grid[curr_row][curr_col]=='w'){
    			curr_row++;
    			len++;
    		}
    		if(len<3)
    			return false;
    	}
    }
    return true;
}

bool isCrossWordGrid(vector<vector<char>>& grid){
    if(!checkWordLen(grid))
        return false;
    if(!checkReachable(grid))
        return false;
    if(!RotationalSymmetric(grid))
        return false;
    return true;
}

int main() {
    vector<vector<char>> cross_word = {{'w','w','w'},
                                       {'w','w','w'},
                                       {'w','w','w'},
                                       {'w','w','w'}};
    cout<<isCrossWordGrid(cross_word)<<endl;
	return 0;
}
