/*****************************************************************************************************************************
This problem was asked by Twitter.
A teacher must divide a class of students into two teams to play dodgeball. Unfortunately, not all the kids get along, 
and several refuse to be put on the same team as that of their enemies.
Given an adjacency list of students and their enemies, write an algorithm that finds a satisfactory pair of teams, 
or returns False if none exists.
For example, given the following enemy graph you should return the teams {0, 1, 4, 5} and {2, 3}.
students = {
    0: [3],
    1: [2],
    2: [1, 4],
    3: [0, 4, 5],
    4: [2, 3],
    5: [3]
}
On the other hand, given the input below, you should return False.
students = {
    0: [3],
    1: [2],
    2: [1, 3, 4],
    3: [0, 2, 4, 5],
    4: [2, 3],
    5: [3]
}
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

bool bipertite(int src,map<int,vector<int>>& adj,vector<int>& group){
    group[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto ememy:adj[u]){
            if(group[ememy] == -1){
                group[ememy] = 1-group[u];
                q.push(ememy);
            }
            else if(group[ememy] == group[u])
                return false;
        }
    }
    return true;
}

vector<vector<int>> findTeams(map<int,vector<int>>adj){
    vector<int> group1, group2;
    vector<int> group(adj.size(),-1);
    for(int i=0;i<adj.size();i++){
        if(group[i]==-1 && !bipertite(i,adj,group))
            return {group1,group2};
    }
    for(int i=0;i<group.size();i++){
        if(group[i]==0)
            group1.push_back(i);
        else
            group2.push_back(i);
    }
    return {group1,group2};
}

int main() {
    map<int,vector<int>> adj;
    adj[0] = {3};
    adj[1] = {2};
    adj[2] = {1,4};
    adj[3] = {0,4,5};
    adj[4] = {2,3};
    adj[5] = {3};
    vector<vector<int>> ans = findTeams(adj);
    for(auto group:ans){
        if(group.size()==0){
            cout<<"Not possbile"<<endl;
            break;
        }
        for(auto student:group)
            cout<<student<<" ";
        cout<<endl;
    }
	return 0;
}
