/****************************************************************************************************************************************
This problem was asked by Google.
Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the 
non-duplicated integer.
For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.
Do this in O(N) time and O(1) space.
Solution explaination : https://www.careercup.com/question?id=7902674
******************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int non_duplicate(vector<int> numbers){
	int one=0,two=0,common_bits;
	for(int i=0;i<numbers.size();i++){
		two = two|(one & numbers[i]);
		one = one^numbers[i];
		common_bits = ~(one&two);
		one&=common_bits;
		two&=common_bits;
	}
	return one;
}


int main() {
	vector<int> numbers = {6, 1, 3, 3, 3, 6, 6};
	cout<<non_duplicate(numbers);
	return 0;
}
