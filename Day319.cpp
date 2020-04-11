/*****************************************************************************************************************************
This problem was asked by Airbnb.
An 8-puzzle is a game played on a 3 x 3 board of tiles, with the ninth tile missing. The remaining tiles are labeled 1 
through 8 but shuffled randomly. Tiles may slide horizontally or vertically into an empty space, but may not be removed 
from the board.
Design a class to represent the board, and find a series of steps to bring the board to the state 
[[1, 2, 3], [4, 5, 6], [7, 8, None]].
*****************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> row = {1, 0, -1, 0};
vector<int> col = {0, -1, 0, 1};

class Node{
  public:
  Node* parent;
  vector<vector<int>> state;
  int x,y,cost,level;
  Node(vector<vector<int>> state,int x,int y,int xnew,int ynew,int level,Node* parent){
      this->parent = parent;
      swap(state[x][y],state[xnew][ynew]);
      this->state = state;
      this->cost = INT_MAX;
      this->level = level;
      this->x = xnew;
      this->y = ynew;
  }
};

struct comp{
    bool operator()(const Node* a,const Node* b)const{
        return (a->cost+a->level) > (b->cost+b->level);
    }
};

int calculateCost(vector<vector<int>>& initial,vector<vector<int>>& final){
    int cost = 0;
    for(int i=0;i<initial.size();i++){
        for(int j=0;j<final.size();j++){
            if(initial[i][j] != final[i][j])
                cost++;
        }
    }
    return cost;
}

bool isSafe(int x,int y){
    return (x>=0 && x<3 && y>=0 && y<3);
}

int printMatrix(vector<vector<int>> mat){ 
    for(int i=0;i<mat.size();i++){ 
        for(int j=0;j<mat.size();j++) 
            cout<<mat[i][j]<<" "; 
        cout<<endl;
    } 
}

void printPath(Node* root){
    if(!root)
        return;
    printPath(root->parent);
    printMatrix(root->state);
    cout<<endl;
}

void solvePuzzle(vector<vector<int>>& initial, vector<vector<int>>& final){
    int x,y;
    for(int i=0;i<initial.size();i++){
        for(int j=0;j<initial[i].size();j++){
            if(initial[i][j]==0){
                x = i, y = j;
                break;
            }
        }
    }
    priority_queue<Node*, vector<Node*>, comp> pq;
    // cout<<x<<" "<<y<<endl;
    Node* root = new Node(initial,x,y,x,y,0,NULL);
    // printMatrix(root->state);
    root->cost = calculateCost(initial,final);
    pq.push(root);
    // cout<<root->cost;
    while(!pq.empty()){
        Node* curr = pq.top();
        pq.pop();
        if(curr->cost==0){
            printPath(curr);
            return;
        }
        // cout<<pq.size()<<endl;
        for(int i=0;i<4;i++){
            int newx = curr->x + row[i], newy = curr->y + col[i];
            if(isSafe(newx,newy)){
                Node* nxt = new Node(curr->state,curr->x,curr->y,newx,newy,curr->level+1,curr);
                nxt->cost = calculateCost(nxt->state,final);
                // printMatrix(nxt->state);
                // cout<<nxt->cost<<endl;
                pq.push(nxt);
            }
        }
    }
}

int main() {
    vector<vector<int>> initial = {{1, 2, 3}, 
                                   {5, 6, 0}, 
                                   {7, 8, 4}};
    vector<vector<int>> final = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 0}};
    solvePuzzle(initial,final);
	return 0;
}
