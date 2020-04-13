/******************************************************************************************************************************
This problem was asked by Dropbox.
Create an algorithm to efficiently compute the approximate median of a list of numbers.
More precisely, given an unordered list of N numbers, find an element whose rank is between N / 4 and 3 * N / 4, 
with a high level of certainty, in less than O(N) time.
Reference : https://www.geeksforgeeks.org/randomized-algorithms-set-3-12-approximate-median/
******************************************************************************************************************************/

#include<bits/stdc++.h> 
using namespace std; 

int approxMedian(vector<int>& arr){ 
	random_device rand_dev; 
	mt19937 generator(rand_dev()); 
	int n = arr.size();
	uniform_int_distribution<int> distribution(0, n-1); 
	if (n==0) 
		return 0; 
	int k = 10*log2(n);
	set<int> s; 
	for (int i=0; i<k; i++){ 
		int index = distribution(generator); 
		s.insert(arr[index]); 
	} 
	auto itr = s.begin(); 
	advance(itr, (s.size()/2) - 1); 
	return *itr; 
} 


int main(){
	vector<int> arr = {1, 3, 2, 4, 5, 6, 8, 7}; 
	cout<<approxMedian(arr)<<endl; 
	return 0; 
} 
