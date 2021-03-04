/*************************************************************************************************************************************************************
This problem was asked by Netflix.
Given an array of integers, determine whether it contains a Pythagorean triplet. Recall that a Pythogorean triplet (a, b, c) is defined by the 
equation a2+ b2= c2.
*************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

bool containsPythogoreanTriplet(vector<int> arr){
	unordered_set<int> mp;
	for(auto ele:arr)
		mp.insert(ele*ele);
	int n = arr.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int s = arr[i]*arr[i] + arr[j]*arr[j];
			if(mp.find(s)!=mp.end()){
				cout<<arr[i]<<" "<<arr[j]<<" "<<sqrt(s)<<endl;
				return true;
			}
		}
	}
	return false;
}

int main() {
	vector<int> arr = {3, 2, 4, 6, 5};
	cout<<containsPythogoreanTriplet(arr)<<endl;
	return 0;
}
