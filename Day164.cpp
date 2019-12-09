/*****************************************************************************************************************************************
This problem was asked by Google.
You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}. By the pigeonhole principle, there must be 
a duplicate. Find it in linear time and space.
*****************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

int findRepeating(vector<int> arr){
	int n = arr.size();
	long long sum = (n*(n-1))/2;
	for(int i=0;i<arr.size();i++)
		sum -= arr[i];
	return -(sum);
}

int findRepeating1(vector<int> arr){
	for(int i=0;i<arr.size();i++){
		if(arr[abs(arr[i])]<0)
			return abs(arr[i]);
		arr[abs(arr[i])] *= -1;
	}
}

int main() {
	vector<int> arr = {1,2,3,4,5,6,7,8,8};
	cout<<findRepeating(arr)<<endl;
	cout<<findRepeating1(arr)<<endl;
	return 0;
}
