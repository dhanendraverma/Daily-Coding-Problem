/*****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Facebook.
Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements
that appear only once.
For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.
Follow-up: Can you do this in linear time and constant space?
*****************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

void findNonRepeating(vector<int> arr){
	int first = 0,second = 0,all_xor = arr[0];
	for(int i=1;i<arr.size();i++)
		all_xor ^= arr[i];
	int right_most = (all_xor&~(all_xor-1));
	for(int i=0;i<arr.size();i++){
		if(arr[i]&right_most)
			first ^= arr[i];
		else
			second ^= arr[i];
	}
	cout<<first<<" "<<second<<endl;
}

int main() {
	vector<int> arr = {1, 2, 4, 6, 8, 10, 2, 6, 10, 8};
	findNonRepeating(arr);
	return 0;
}
