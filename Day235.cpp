/****************************************************************************************************************************
This problem was asked by Facebook.
Given an array of numbers of length N, find both the minimum and maximum using less than 2 * (N - 2) comparisons.
*****************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

pair<int,int> minMax(vector<int> arr){
	pair<int,int> ans;
	int n=arr.size();
	if(n%2)
		ans = {arr[0],arr[0]};
	else
		ans = {min(arr[0],arr[1]),max(arr[0],arr[1])};
	int i= n%2?1:2;
	while(i<n-1){
		if(arr[i]<arr[i+1])
			ans = {min(ans.first,arr[i]),max(ans.second,arr[i+1])};
		else
			ans = {min(ans.first,arr[i+1]),max(ans.second,arr[i])};
		i += 2;
	}
	return ans;
}


pair<int,int> minMax(vector<int> arr, int l, int r){
	if(l==r)
		return {arr[l],arr[l]};
	if(r==l+1){
		if(arr[r]>arr[l])
			return {arr[l],arr[r]};
		return {arr[r],arr[l]};
	}
	int mid = (l+r)/2;
	pair<int,int> lans = minMax(arr,l,mid);
	pair<int,int> rans = minMax(arr,mid+1,r);
	return {min(lans.first,rans.first),max(lans.second,rans.second)};
}


int main() {
	vector<int> arr = {1000, 11, 445, 1, 330, 3000};
	pair<int,int> ans = minMax(arr,0,arr.size()-1);
	cout<<ans.first<<" "<<ans.second<<endl;
	ans = minMax(arr);
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
