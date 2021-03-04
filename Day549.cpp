/**************************************************************************************************************************************************************
This problem was asked by Google.
Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.
For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.
Do this in O(N) time and O(1) space.
**************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int findNonDuplicate(vector<int> arr){
	int first = 0; //stores the xored bit representation of numbers seeing for the first time
	int second = 0; //stores the xored bit representation of numbers seeing for the second time
	int common; //stores the common set bits of first and second
	for(auto num:arr){
		second |= (first & num); //when number is already seen before then its bit would be already set in one and hence '&' operation would yield corresponding set bits and '|' operation with two would set them in two, otherwise if number is seen for the first time the '&' operation would generate 0 and second won't get bit stored
		first ^= num; //if first if seen first time the corresponding bits would be set otherwise if already seen then corresponding bits would be unset from first 
		common = ~(first & second); //get the common bits between first and second so it can be used to unset from both first and second
		first &= common;
		second &= common;
	}
	return first; //at last first would remain with the bits of the number seen only once
}


int main() {
	vector<int> arr = {6, 1, 3, 3, 3, 6, 6};
	cout<<findNonDuplicate(arr)<<endl;
	return 0;
}
