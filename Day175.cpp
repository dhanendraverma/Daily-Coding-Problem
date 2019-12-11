/*************************************************************************************************************************************
This problem was asked by Google.
You are given a starting state start, a list of transition probabilities for a Markov chain, and a number of steps num_steps. Run the Markov chain starting from start for num_steps and compute the number of times we visited each state.
For example, given the starting state a, number of steps 5000, and the following transition probabilities:
[
  ('a', 'a', 0.9),
  ('a', 'b', 0.075),
  ('a', 'c', 0.025),
  ('b', 'a', 0.15),
  ('b', 'b', 0.8),
  ('b', 'c', 0.05),
  ('c', 'a', 0.25),
  ('c', 'b', 0.25),
  ('c', 'c', 0.5)
]
One instance of running this Markov chain might produce { 'a': 3012, 'b': 1656, 'c': 332 }.
**************************************************************************************************************************************/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
using namespace std;

class State{
	public:
	char src;
	char tar;
	int prob;
	State(char src, char tar, int prob){
		this->src = src;
		this->tar = tar;
		this->prob = prob;
	}
};

char findNewState(char start, map<char,pair<vector<char>,vector<int>>>& transmap){
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	cout<<r<<endl;
	auto it = lower_bound(transmap[start].second.begin(),transmap[start].second.end(),r);
	int idx = it-transmap[start].second.begin();
	cout<<idx<<endl;
	return transmap[start].first[idx];
}


map<char,pair<vector<char>,vector<int>>> findTransMap(vector<State> trans){
	map<char,pair<vector<char>,vector<int>>> transmap;
	for(auto state:trans){
		if(transmap.find(state.src)==transmap.end()){
			transmap[state.src] = {{state.tar},{state.prob}};
		}
		else{
			transmap[state.src].first.push_back(state.tar);
			int prev_prob = transmap[state.src].second.back();
			transmap[state.src].second.push_back(prev_prob+state.prob);
		}
	}
	return transmap;
}

map<char,int> findTransition(vector<State> trans, char start, int steps){
	map<char,pair<vector<char>,vector<int>>> transmap = findTransMap(trans);
	map<char,int> hits;
	while(steps--){
		hits[start]++;
		start = findNewState(start,transmap);
		cout<<start<<endl;
	}
	return hits;
}


int main() {
	char start = 'a';
	int steps = 5000;
	vector<State> transitions;
	transitions.push_back(State('a', 'a', 0.9));
	transitions.push_back(State('a', 'b', 0.075));
	transitions.push_back(State('a', 'c', 0.025));
	transitions.push_back(State('b', 'a', 0.15));
	transitions.push_back(State('b', 'b', 0.8));
	transitions.push_back(State('b', 'c', 0.05));
	transitions.push_back(State('c', 'a', 0.25));
	transitions.push_back(State('c', 'b', 0.25));
	transitions.push_back(State('c', 'c', 0.5));
	map<char,int> trans = findTransition(transitions,start,steps);
	for(auto itr=trans.begin();itr!=trans.end();itr++)
		cout<<itr->first<<" "<<itr->second<<endl;
	return 0;
}
