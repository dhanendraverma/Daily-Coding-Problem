/*****************************************************************************************************************************************
This problem was asked by Uber.
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element in O(log N) time.
You may assume the array does not contain duplicates.
For example, given [5, 7, 10, 3, 4], return 3.
******************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr,int low, int high){
	if(high<low)
		return arr[0];
	if(high==low)
		return arr[low];
	int mid = low + (high-low)/2;
	if(mid<high && arr[mid+1]<arr[mid])
		return arr[mid+1];
	if(mid>low && arr[mid]<arr[mid-1])
		return arr[mid];
	if(arr[high]>arr[mid])
		return binarySearch(arr,low,mid-1);
	return binarySearch(arr,mid+1,high);
}



int findMin(vector<int> rotatedArr){
	return binarySearch(rotatedArr,0,rotatedArr.size()-1);
}


int main() {
	vector<int> rotatedArr = {6,7,8,9,10,1,2,3,4,5};
	cout<<findMin(rotatedArr)<<endl;
	return 0;
}
