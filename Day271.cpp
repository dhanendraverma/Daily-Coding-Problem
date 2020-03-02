/*****************************************************************************************************************************
This problem was asked by Netflix.
Given a sorted list of integers of length N, determine if an element x is in the list without performing any multiplication, 
division, or bit-shift operations.
Do this in O(log N) time.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool findX(vector<int>& arr,int x){
	int low = 0, high = arr.size()-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(arr[mid]==x)
			return 1;
		if(arr[mid]<x)
			low = mid+1;
		else
			high = mid-1;
	}
	return 0;
}

int main() {
	vector<int> arr = {1,2,3,4,5,6,8,9};
	int x = 7;
	cout<<findX(arr,x)<<endl;
	return 0;
}
