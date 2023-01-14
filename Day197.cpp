/****************************************************************************************************************************************
This problem was asked by Amazon.
Given an array and a number k that's smaller than the length of the array, rotate the array to the right k elements in-place.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateKright(vector<int>& arr, int k){
        int n = arr.size();
        reverse(arr.begin(), arr.begin()+(n-k));
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
}


int main() {
	vector<int> arr = {1,2,3,4,5,6};
	int k = 4;
	rotateKright(arr,k);
	for(auto i:arr)
		cout<<i<<" ";
	return 0;
}
