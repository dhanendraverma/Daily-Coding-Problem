/*****************************************************************************************************************************
This problem was asked by Etsy.
Given an array of numbers N and an integer k, your task is to split N into k partitions such that the maximum sum of any
partition is minimized. Return this sum.
For example, given N = [5, 1, 2, 7, 3, 4] and k = 3, you should return 8, since the optimal partition is
[5, 1, 2], [7], [3, 4].
*****************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//check if current sum(mid) can be achieved using how many partition of array
int noOFkRequired(vector<int> arr,int n,int mid){
	int curr_sum=0,k=1;
	for(int i=0;i<n;i++){
		curr_sum += arr[i];
		if(curr_sum>mid){
			curr_sum = arr[i];
			k++;
		}
	}
	return k;
}

int minOfMaxSum(vector<int> arr,int k){
	int n = arr.size();
	int low=INT_MIN,high=0,ans;
	for(int i=0;i<n;i++){
		low = max(low,arr[i]); //min sum would be maximum element of arr which creates thw subarray of size one
		high += arr[i]; //maximum sum possible would be when k=1 and whole arr is sumed up
	}
	while(low<=high){
		int mid = low + (high-low)/2;
		if(noOFkRequired(arr,n,mid)<=k){ //if current sum can be achieved using the less than  partition, but more partition can be done and sum can be decreased.
			high = mid-1;
			ans = mid;
		}
		else //if more values can be accomodated 
			low = mid+1;
	}
	return ans;
}

int main() {
	vector<int> arr = {5, 1, 2, 7, 3, 4};
	int k = 3;
	cout<<minOfMaxSum(arr,k);
	return 0;
}
