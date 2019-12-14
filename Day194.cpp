/*****************************************************************************************************************************************
This problem was asked by Facebook.
Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0 and the other list q1, q2, ..., qn on the line 
y = 1. Imagine a set of n line segments connecting each point pi to qi. Write an algorithm to determine how many pairs of the line 
segments intersect.
******************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int crossings(vector<int> P, vector<int> Q){
	//making pairs so sorted order in P also permutes the Q values accordingly
	vector<pair<int,int>> PQ(P.size());
	for(int i=0;i<P.size();i++)
		PQ[i] = {P[i],Q[i]};
	sort(PQ.begin(),PQ.end());
	multiset<int> mset;
	int intr =0;
	//now just count how for evey P values how many Ps are there whose Q value is greater and thses 
	// Ps comes before in sorted P values.(counting inversions)
	mset.insert(PQ[0].second);
	for(int i=1;i<PQ.size();i++){
		mset.insert(PQ[i].second);
		auto pos = mset.upper_bound(PQ[i].second);
		intr += distance(pos,mset.end());
	}
	return intr;
}

int main() {
	vector<int> P = {6,2,4,3,5,1};
	vector<int> Q = {1,6,5,2,3,4};
	cout<<crossings(P,Q)<<endl;
	return 0;
}
