/*****************************************************************************************************************************************
This problem was asked by Google.
Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. If there are multiple smallest sets,
return any of them.
For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], one set of numbers that covers all these intervals is {3, 6}.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int,int> findSmallestSet(vector<pair<int,int>> intervals){
	pair<int,int> ans = {INT_MAX,INT_MIN};
	for(int i=0;i<intervals.size();i++){
		if(intervals[i].first>ans.second)
			ans.second = intervals[i].first;
		if(intervals[i].second<ans.first)
			ans.first = intervals[i].second;
	}
	return ans;
}

int main() {
	vector<pair<int,int>> intervals = {{0, 3}, {2, 6}, {3, 4}, {6, 9}};
	pair<int,int> smallestSet = findSmallestSet(intervals);
	cout<<"{"<<smallestSet.first<<" "<<smallestSet.second<<"}"<<endl;
	return 0;
}
