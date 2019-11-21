/****************************************************************************************************************************************
This problem was asked by Amazon.
Given an array of numbers, find the maximum sum of any contiguous subarray of the array.
For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.
Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.
Do this in O(N) time.
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int cont_max(vector<int> numbers){
	int mx = 0,mx_sofar=0;
	for(int i=0;i<numbers.size();i++){
		mx_sofar += numbers[i];
		if(mx_sofar<0)
			mx_sofar = 0;
		mx = max(mx,mx_sofar);
	}
	return mx;
}

int main() {
	vector<int> numbers = {34, -50, 42, 14, -5, 86};
	cout<<cont_max(numbers);
	return 0;
}
