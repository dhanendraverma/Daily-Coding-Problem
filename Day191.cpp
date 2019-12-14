/*****************************************************************************************************************************************
This problem was asked by Stripe.
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.
For example, given the intervals (7, 9), (2, 4), (5, 8), return 1 as the last interval can be removed and the first two won't overlap.
The intervals are not necessarily sorted in any order.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b){
	if(a[1]==b[1])
		return a[0]<b[0];
	return a[1]<b[1];
}

int MinDel(vector<vector<int>> intervals){
	sort(intervals.begin(),intervals.end(),comp);
	int ans=0,prev=0;
	for(int i=1;i<intervals.size();i++){
		if(intervals[i][0]<intervals[prev][1])
			ans++;
		else
			prev = i;
	}
	return ans;
}

int main() {
	vector<vector<int>> intervals = {{7, 9},{2, 4},{5, 8}};
	cout<<MinDel(intervals)<<endl;
	return 0;
}
