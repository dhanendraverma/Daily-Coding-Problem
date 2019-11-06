/*****************************************************************************************************************************************
This problem was asked by Snapchat.
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*****************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int min_rooms(vector<int> arrival, vector<int> depart,int n){
	sort(arrival.begin(),arrival.end());
	sort(depart.begin(),depart.end());
	int rooms=1,ans=1;
	int i=1,j=0;
	while(i<n && j<n){
		if(arrival[i]<=depart[j]){
			rooms++;
			ans = ans<rooms?rooms:ans;
			i++;
		}
		else{
			rooms--;
			j++;
		}
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	vector<int> arrival(n),depart(n);
	for(int i=0;i<n;i++){
		cin>>arrival[i]>>depart[i];
	}
	cout<<min_rooms(arrival,depart,n);
	return 0;
}
