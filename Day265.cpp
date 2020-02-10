/*****************************************************************************************************************************
This problem was asked by Atlassian.
MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written. They would like to give 
the smallest positive amount to each worker consistent with the constraint that if a developer has written more lines of code
than their neighbor, they should receive more money.
Given an array representing a line of seats of employees at MegaCorp, determine how much each one should get paid.
For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
******************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> calculateBonus(vector<int> arr){
	vector<int> bonus;
	if(arr.size()<1)
		return bonus;
	else if(arr.size()<2)
		return {1};
	int inc = arr[1]>arr[0];
	int start = 0;
	vector<pair<int,int>> segments;
	for(int i=1;i<arr.size();i++){
		if((inc && arr[i]<arr[i-1]) || (!inc && arr[i]>arr[i-1])){
			segments.push_back({inc,i-start});
			start = i;
			inc = !inc;
		}
	}
	segments.push_back({inc,arr.size()-start});
	
	for(auto seg:segments){
		cout<<seg.first<<" "<<seg.second<<endl;
		int i=1;
		// int i = seg.first?2:1;
		while(i<=seg.second)
			bonus.push_back(i++);
		// if(inc)
		// 	bonus.push_back(seg.second);
		if(!seg.first)
			reverse(bonus.end()-seg.second,bonus.end());
	}
	return bonus;
}

int main() {
	vector<int> arr = {10, 40, 200, 1000, 60, 30};
	vector<int> bonus = calculateBonus(arr);
	for(auto b:bonus)
		cout<<b<<" ";
	return 0;
}
