/***************************************************************************************************************************************
This problem was asked by Google.
Given an array of integers, return a new array where each element in the new array is the number of smaller elements to the right of 
that element in the original input array.
For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:
There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1

***************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> rightSmaller(vector<int> arr){
	int n = arr.size();
	stack<int> s;
	vector<int> smaller(n);
	s.push(arr[n-1]);
	smaller[n-1] = 0;
	for(int i=n-2;i>=0;i--){
		if(arr[i]>s.top()){
			smaller[i] = s.size();
			s.push(arr[i]);
		}
		else if(arr[i]==s.top()){
			smaller[i] = smaller[i+1];
			s.push(arr[i]);
		}
		else{
			while(arr[i]<s.top())
				s.pop();
			smaller[i] = s.size();
			s.push(arr[i]);
		}
	}
	return smaller;
}

int main() {
	vector<int> arr= {3, 4, 9, 6,6,6, 1};
	vector<int> rSmaller = rightSmaller(arr);
	for(auto i:rSmaller)
		cout<<i<<" ";
	return 0;
}
