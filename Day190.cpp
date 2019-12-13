/*****************************************************************************************************************************************
This problem was asked by Facebook.
Given a circular array, compute its maximum subarray sum in O(n) time. A subarray can be empty, and in this case the sum is 0.
For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.
Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int> arr){
	int curr=0,max_sum=0;
	for(int i=0;i<arr.size();i++){
		curr += arr[i];
		if(curr<0)
			curr = 0;
		if(curr>max_sum)
			max_sum = curr;
	}
	return max_sum;
}

int MaxSubSum(vector<int> arr){
	int k = kadane(arr),total=0;
	for(int i=0;i<arr.size();i++){
		total += arr[i];
		arr[i] = -arr[i];
	}
	int k2 = total+kadane(arr);
	return max(k2,k);
}


int main() {
	vector<int> arr ={1,2,8, -1, 3,-5,4};
	cout<<MaxSubSum(arr);
	return 0;
}
