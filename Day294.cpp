/*****************************************************************************************************************************
This problem was asked by Square.
A competitive runner would like to create a route that starts and ends at his house, with the condition that the route goes 
entirely uphill at first, and then entirely downhill.
Given a dictionary of places of the form {location: elevation}, and a dictionary mapping paths between some of these locations
to their corresponding distances, find the length of the shortest route satisfying the condition above. Assume the runner's
home is location 0.
For example, suppose you are given the following input:
elevations = {0: 5, 1: 25, 2: 15, 3: 20, 4: 10}
paths = {
    (0, 1): 10,
    (0, 2): 8,
    (0, 3): 15,
    (1, 3): 12,
    (2, 4): 10,
    (3, 4): 5,
    (3, 0): 17,
    (4, 0): 10
}
In this case, the shortest valid path would be 0 -> 2 -> 4 -> 0, with a distance of 28.
*****************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <set>
#include <stack>
using namespace std;

void topologicalRec(map<int,vector<pair<int,int>>> &graph, set<int>& visited, stack<int>& order, int u){
    if(visited.find(u)==visited.end()){
        for(auto edge:graph[u]){
            topologicalRec(graph,visited,order,edge.first);
        }
        visited.insert(u);
        order.push(u);
    }
}

stack<int> topologicalSort(map<int,vector<pair<int,int>>> graph, int src){
    set<int> visited;
    stack<int> order;
    topologicalRec(graph,visited,order,src);
    return order;
}

vector<int> getDistance(map<int,vector<pair<int,int>>> graph,stack<int> order,int n){
    vector<int> distance(n,INT_MAX);
    distance[0] = 0;
    while(!order.empty()){
        int curr = order.top();
        order.pop();
        for(auto edge:graph[curr]){
            distance[edge.first] = min(distance[edge.first],distance[curr]+edge.second);
        }
    }
    return distance;
}

int shortIncDecPath(map<int,int> elevations,vector<vector<int>> paths){
    map<int,vector<pair<int,int>>> risingGraph, fallingGraph;
    for(auto edge:paths){
        if(elevations[edge[0]]<elevations[edge[1]])
            risingGraph[edge[0]].push_back({edge[1],edge[2]});
        else if(elevations[edge[0]]>elevations[edge[1]])
            fallingGraph[edge[1]].push_back({edge[0],edge[2]});
    }
    stack<int> risingOrder = topologicalSort(risingGraph,0);
    stack<int> fallingOrder = topologicalSort(fallingGraph,0);
    vector<int> rising = getDistance(risingGraph,risingOrder,elevations.size());
    vector<int> falling = getDistance(fallingGraph,fallingOrder,elevations.size());
    int ans = INT_MAX;
    for(int i=1;i<elevations.size();i++){
        if(rising[i]<INT_MAX && falling[i]<INT_MAX)
            ans = min(ans,rising[i]+falling[i]);
    }
    return ans;
}

int main() {
    map<int,int> elevations = {{0, 5}, {1, 25}, {2, 15}, {3, 20}, {4, 10}};
    vector<vector<int>> paths = {{0,1,10},
                                {0,2,8},
                                {0,3,15},
                                {1,3,12},
                                {2,4,10},
                                {3,4,5},
                                {3,0,17},
                                {4,0,10}};
    cout<<shortIncDecPath(elevations,paths);
	return 0;
}
