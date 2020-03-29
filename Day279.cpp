/*****************************************************************************************************************************
This problem was asked by Twitter.
A classroom consists of N students, whose friendships can be represented in an adjacency list. For example, the following 
descibes a situation where 0 is friends with 1 and 2, 3 is friends with 6, and so on.
{
    0: [1, 2],
    1: [0, 5],
    2: [0],
    3: [6],
    4: [],
    5: [1],
    6: [3]
}
Each student can be placed in a friend group, which can be defined as the transitive closure of that student's friendship 
relations. In other words, this is the smallest set such that no student in the group has any friends outside this group. 
For the example above, the friend groups would be {0, 1, 2, 5}, {3, 6}, {4}.
Given a friendship list such as the one above, determine the number of friend groups in the class.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
  public:
    int V;
    list<int>* adj;
    Graph(int V){
        this->V = V;
        this->adj = new list<int>[V];
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    void DFS(int u,vector<bool>& visited){
        visited[u] = true;
        for(auto v:adj[u]){
            if(!visited[v])
                DFS(v,visited);
        }
    }
    
    void countGroups(){
        int cnt=0;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cnt++;
                DFS(i,visited);
            }
        }
        cout<<cnt<<endl;
    }
};



int main() {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,0);
    g.addEdge(1,5);
    g.addEdge(2,0);
    g.addEdge(3,6);
    g.addEdge(5,1);
    g.addEdge(6,3);
    g.countGroups();
	return 0;
}
