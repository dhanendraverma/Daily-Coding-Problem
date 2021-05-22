/*****************************************************************************************************************************
This problem was asked by Samsung.
A group of houses is connected to the main water plant by means of a set of pipes. A house can either be connected by a 
set of pipes extending directly to the plant, or indirectly by a pipe to a nearby house which is otherwise connected.
For example, here is a possible configuration, where A, B, and C are houses, and arrows represent pipes:
A <--> B <--> C <--> plant
Each pipe has an associated cost, which the utility company would like to minimize. Given an undirected graph of pipe 
connections, return the lowest cost configuration of pipes such that each house has access to water.
In the following setup, for example, we can remove all but the pipes from plant to A, plant to B, and B to C, for a total 
cost of 16.
pipes = {
    'plant': {'A': 1, 'B': 5, 'C': 20},
    'A': {'C': 15},
    'B': {'C': 10},
    'C': {}
}
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;

class UnionFind{
	public:
		map<char, pair<char,int>> subset;
		UnionFind(map<char, vector<pair<char, int>>> adj_list){
			for(auto p:adj_list)
				subset[p.first] = {p.first,0};
		}
		
		char find(char a){
			if(subset[a].first != a)
				subset[a].first = find(subset[a].first);
			return subset[a].first;
		}
		
		void Union(char a, char b){
			char aparent = find(a);
			char bparent = find(b);
			
			if(subset[aparent].second < subset[bparent].second)
				subset[aparent].first = bparent;
			else if(subset[aparent].second > subset[bparent].second)
				subset[bparent].first = aparent;
			else{
				subset[bparent].first = aparent;
				subset[aparent].second++;
			}
		}
};


int lowestCostConfig( map<char, vector<pair<char,int>>> adj_list){
	vector<pair<int, pair<char,char>>> edges;
	for(auto edge:adj_list){
		for(auto child:edge.second)
			edges.push_back({child.second, {edge.first, child.first}});
	}
	sort(edges.begin(), edges.end());
	UnionFind uf(adj_list);
	int total = 0;
	for(int i=0; i<adj_list.size(); i++){
		char x = uf.find(edges[i].second.first);
		char y = uf.find(edges[i].second.second);
		
		if(x!=y){
			cout<<edges[i].second.first<<" "<<edges[i].second.second<<" "<<edges[i].first<<endl;
			uf.Union(x,y);
			total += edges[i].first;
		}
	}
	return total;
}

int lowestCostConf(map<char,vector<pair<char,int>>> graph){
    priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
    map<char,int> keys, parent, inMST;
    for(auto u:graph){
        keys[u.first] = INT_MAX;
        parent[u.first] = -1;
        inMST[u.first] = 0;
    }
    pq.push({0,'P'});
    keys['p'] = 0;
    int s = 0;
    while(!pq.empty()){
        char curr = pq.top().second;
        pq.pop();
        inMST[curr] = 1;
        for(auto edge:graph[curr]){
            if(inMST[edge.first]==0 && keys[edge.first]>edge.second){
                keys[edge.first] = edge.second;
                pq.push({edge.second,edge.first});
                parent[edge.first] = curr;
            }
        }
    }
    for(auto u:graph){
        if(u.first!='P'){
            cout<<char(parent[u.first])<<" "<<u.first<<endl;
            s += keys[u.first];
        }
    }
    return s;
}

int main() {
    map<char,vector<pair<char,int>>> graph;
    graph['P'] = {{'A',1},{'B',5},{'C',20}};
    graph['A'] = {{'C',15}};
    graph['B'] = {{'C',10}};
    graph['C'] = {};
    cout<<lowestCostConf(graph)<<endl;
    cout<<lowestCostConfig(graph)<<endl;
    return 0;
}
