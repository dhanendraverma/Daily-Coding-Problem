/*****************************************************************************************************************************
This problem was asked by Adobe.
You are given a tree with an even number of nodes. Consider each connection between a parent and child node to be an "edge".
You would like to remove some of these edges, such that the disconnected subtrees that remain each have an even number of nodes.
For example, suppose your input was the following tree:

   1
  / \ 
 2   3
    / \ 
   4   5
 / | \
6  7  8
In this case, removing the edge (3, 4) satisfies our requirement.
Write a function that returns the maximum number of edges you can remove while still satisfying this requirement.
******************************************************************************************************************************/



#include <iostream>
#include <map>
#include <vector>
using namespace std;

void addEdge(int a,int b,map<int,vector<int>>& graph){
    graph[a].push_back(b);
}

int dfs(map<int,vector<int>>& adj,int u,int& ans){
    int curr_nodes = 0;
    for(int i=0;i<adj[u].size();i++){
        int subtree_nodes = dfs(adj,adj[u][i],ans);
        
        if(subtree_nodes%2 == 0)
            ans++;
        else
            curr_nodes += subtree_nodes;
    }
    // cout<<curr_nodes<<" "<<u<<endl;
    return 1+curr_nodes;
}

int main() {
    map<int,vector<int>> graph;
    addEdge(1,2,graph);
    addEdge(1,3,graph);
    addEdge(3,4,graph);
    addEdge(3,5,graph);
    addEdge(4,6,graph);
    addEdge(4,7,graph);
    addEdge(4,8,graph);
    int ans = 0;
    dfs(graph,1,ans);
    cout<<ans<<endl;
	return 0;
}
