/**************************************************************************************************************************************************************
This problem was asked by Amazon.
Given an array of numbers, find the maximum sum of any contiguous subarray of the array.
For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.
Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.
Do this in O(N) time.
**************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int maxSubraaySum(vector<int> arr){
	int sum_so_far = 0, max_subarray_sum = 0;
	for(auto ele:arr){
		sum_so_far += ele;
		sum_so_far = max(sum_so_far,0);
		max_subarray_sum = max(sum_so_far, max_subarray_sum);
	}
	return max_subarray_sum;
}


int main() {
	vector<int> arr = {34, -50, 42, 14, -5, 86};
	cout<<maxSubraaySum(arr)<<endl;
	return 0;
}
