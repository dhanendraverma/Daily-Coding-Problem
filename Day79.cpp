/****************************************************************************************************************************************
This problem was asked by Facebook.
Given an array of integers, write a function to determine whether the array could become non-decreasing by modifying at most 1 element.
For example, given the array [10, 5, 7], you should return true, since we can modify the 10 into a 1 to make the array non-decreasing.
Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a non-decreasing array.
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int canBeNonDecreasing(vector<int> arr){
	int n = arr.size();
	bool flag = false;
	if(arr[0]>arr[1]){
		arr[0] = arr[1];
		flag = true;
	}
	if(arr[n-1]<arr[n-2]){
		if(flag)
			return false;
		flag  = true;
		arr[n-1] = arr[n-2]; 
	}
	for(int i=2;i<n;i++){
		if(arr[i]<arr[i-1]){
			
			if(flag)
				return false;
			flag = true;
			arr[i] = arr[i-1];
		}
		
	}
	return true;
}

int main() {
	vector<int> arr = {10,5,1};
	cout<<canBeNonDecreasing(arr)<<endl;
	return 0;
}
