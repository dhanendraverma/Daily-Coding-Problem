/****************************************************************************************************************************************
This problem was asked by Snapchat.
Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.
The input list is not necessarily ordered in any way.
For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].
*****************************************************************************************************************************************/


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void merged_intervals(vector<pair<int,int>> intervals){
	sort(intervals.begin(),intervals.end());
	vector<pair<int,int>> merged;
	pair<int,int> temp = intervals[0];
	for(int i=1;i<intervals.size();i++){
		cout<<temp.first<<" "<<temp.second<<endl;
		if(temp.second>=intervals[i].first){
			if(intervals[i].second>temp.second)
				temp.second = intervals[i].second;
		}
		else
		{
			merged.push_back(temp);
			temp = intervals[i];
		}
	}
	merged.push_back(temp);
	
	for(auto intr: merged)
		cout<<intr.first<<"-"<<intr.second<<endl;
}

int main() {
	vector<pair<int,int>> intervals = {{1, 3}, {5, 8}, {4, 10}, {20, 25}}; 
	merged_intervals(intervals);
	return 0;
}
