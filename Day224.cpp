/****************************************************************************************************************************************
This problem was asked by Amazon.
Given a sorted array, find the smallest positive integer that is not the sum of a subset of the array.
For example, for the input [1, 2, 3, 10], you should return 7.
Do this in O(N) time.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int smallestPosInt(vector<int> arr){
	int ans=1;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>ans)
			return ans;
		ans += arr[i];
	}
	return ans;
}

int main() {
	vector<int> sortedArr = {1, 2, 3, 5};
	cout<<smallestPosInt(sortedArr)<<endl;
	return 0;
}
