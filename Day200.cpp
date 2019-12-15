/****************************************************************************************************************************************
This problem was asked by Microsoft.
Let X be a set of n intervals on the real line. We say that a set of points P "stabs" X if every interval in X contains at least one 
point in P. Compute the smallest set of points that stabs X.
For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should return [4, 9].
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> A, pair<int,int> B){
	if(A.first==B.first)
		return A.second>B.second;
	return A.first<B.first;
}

vector<int> stabPoints(vector<pair<int,int>> intervals){
	vector<int> P;
	sort(intervals.begin(),intervals.end());
	int curr = intervals[0].second;
	for(int i=1;i<intervals.size();i++){
		if(intervals[i].first>curr){
			P.push_back(curr);
			curr = intervals[i].second;
		}
		else if(intervals[i].second<curr)
			curr = intervals[i].second;
	}
	P.push_back(curr);
	return P;
}


int main() {
	vector<pair<int,int>> intervals = {{1,4}, {2,3}, {7,9}, {9,12}};
	vector<int> P = stabPoints(intervals);
	for(auto i:P)
		cout<<i<<" ";
	return 0;
}
