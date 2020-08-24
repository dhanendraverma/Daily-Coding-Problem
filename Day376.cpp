/*****************************************************************************************************************************************************************
This problem was asked by Google.
You are writing an AI for a 2D map game. You are somewhere in a 2D grid, and there are coins strewn about over the map.
Given the position of all the coins and your current position, find the closest coin to you in terms of Manhattan distance. That is, you can move around up, down,
left, and right, but not diagonally. If there are multiple possible closest coins, return any of them.
For example, given the following map, where you are x, coins are o, and empty spaces are . (top left is 0, 0):
---------------------
| . | . | x | . | o |
---------------------
| o | . | . | . | . |
---------------------
| o | . | . | . | o |
---------------------
| . | . | o | . | . |
---------------------
return (0, 4), since that coin is closest. This map would be represented in our question as:
Our position: (0, 2)
Coins: [(0, 4), (1, 0), (2, 0), (3, 2)]
******************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


pair<int,int> closestCoin(vector<vector<char>>& grid,pair<int,int> start){
    queue<pair<pair<int,int>,int>> q;
    q.push({start,0});
    pair<pair<int,int>,int> curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        int x = curr.first.first; 
        int y = curr.first.second;
        int d = curr.second;
        // cout<<x<<y<<endl;
        if(x+1<grid.size()){
            if(grid[x+1][y]=='o')
                return {x+1,y};
            else
                q.push({{x+1,y},d+1});
        }
        if(x-1>=0){
            if(grid[x-1][y]=='o')
                return {x-1,y};
            else
                q.push({{x-1,y},d+1});
        }
        if(y+1<grid[0].size()){
            if(grid[x][y+1]=='o')
                return {x,y+1};
            else
                q.push({{x,y+1},d+1});
        }
        if(y-1>=0){
            if(grid[x][y-1]=='o')
                return {x,y-1};
            else
                q.push({{x,y-1},d+1});
        }
    }
    return {-1,-1};
}

int main() {
    vector<vector<char>> grid = {{'.','.','x','.','o'},
                                {'o','.','.','.','.'},
                                {'o','.','.','.','o'},
                                {'.','.','o','.','.'}};
    pair<int,int> start = {0,2};
    pair<int,int> closest = closestCoin(grid,start);
    cout<<closest.first<<" "<<closest.second<<endl;
	return 0;
}
