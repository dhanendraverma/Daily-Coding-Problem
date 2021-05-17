/*****************************************************************************************************************************
This problem was asked by Spotify.
You have access to ranked lists of songs for various users. Each song is represented as an integer, and more preferred songs
appear earlier in each list. For example, the list [4, 1, 7] indicates that a user likes song 4 the best, followed by songs 1
and 7.
Given a set of these ranked lists, interleave them to create a playlist that satisfies everyone's priorities.
For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}. In this case a satisfactory playlist could be
[2, 1, 6, 7, 3, 9, 5].
******************************************************************************************************************************/


#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;

class Graph{
    public:
    map<int,vector<int>> adj;
    Graph(){
    }
    void addEdge(int u,int v){
        // cout<<u<<" "<<v<<endl;
        adj[u].push_back(v);
    }
    
    void topologicalSortRec(int u,set<int>& visited,stack<int>& order){
        visited.insert(u);
        for(auto v:adj[u]){
            if(visited.find(v)==visited.end())
                topologicalSortRec(v,visited,order);
        }
        order.push(u);
    }
    
    void topologicalSort(){
        stack<int> order;
        set<int> visited;
        for(auto edge:adj){
            if(visited.find(edge.first)==visited.end())
                topologicalSortRec(edge.first,visited,order);
        }
        while(!order.empty()){
            cout<<order.top()<<" ";
            order.pop();
        }
    }
};

void createPlayList(vector<vector<int>>& rank_list){
    Graph g;
    for(auto list:rank_list){
        for(int i=0;i<list.size()-1;i++)
            g.addEdge(list[i],list[i+1]);
    }
    g.topologicalSort();
}

int main() {
    vector<vector<int>> rank_list;
    rank_list.push_back({1, 7, 3});
    rank_list.push_back({2, 1, 6, 7, 9});
    rank_list.push_back({3, 9, 5});
    createPlayList(rank_list);
	return 0;
}
