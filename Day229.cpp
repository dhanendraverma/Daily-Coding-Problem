#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int smallestTurns(map<int,int>& snakes, map<int,int>& ladder){
	vector<bool> visited(100,false);
	queue<pair<int,int>> q;
	pair<int,int> curr;
	q.push({0,0});
	visited[0] = true;
	while(!q.empty()){
		curr = q.front();
		if(curr.first==99)
			return curr.second;
		q.pop();
		for(int i=curr.first+1;i<=(6+curr.first) && i<100;i++){
			if(!visited[i]){
				if(snakes.find(i)!=snakes.end())
					q.push({snakes[i],curr.second+1});
				else if(ladder.find(i)!=ladder.end())
					q.push({ladder[i],curr.second+1});
				else
					q.push({i,curr.second+1});
				visited[i]=true;
			}
		}
	}
	return curr.second;
}

int main() {
	map<int,int> snakes = {{16,6}, {48,26}, {49,11}, {56,53}, {62,19}, {64,60}, {87,24}, {93,73}, {95,75}, {98,78}};
	map<int,int> ladder = {{1,38}, {4,14}, {9,31}, {21,42}, {28,84}, {36,44}, {51,67}, {71,91}, {80,100}};
	cout<<smallestTurns(snakes,ladder)<<endl;
	return 0;
}
