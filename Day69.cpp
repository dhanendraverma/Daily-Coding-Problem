/**************************************************************************************************************************************
This problem was asked by Facebook.
Given a list of integers, return the largest product that can be made by multiplying any three integers.
For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.
You can assume the list has at least three integers.
**************************************************************************************************************************************/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

long long find_max_triplet2(vector<int> arr){
	if(arr.size()<3){
		cout<<"arr doesn't have sufficient element";
		exit(0);
	}
	sort(arr.begin(),arr.end());
	int n = arr.size();
	return max(arr[n-1]*arr[n-2]*arr[n-1],arr[n-1]*arr[0]*arr[0]);
}

long long find_max_triplet(vector<int> arr){
	if(arr.size()<3){
		cout<<"arr doesn't have sufficient element";
		exit(0);
	}
	int first_max=INT_MIN,second_max=INT_MIN,third_max=INT_MIN;
	int first_min = INT_MAX,second_min=INT_MAX;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>first_max){
			third_max = second_max;
			second_max = first_max;
			first_max = arr[i];
		}
		else if(arr[i]>second_max){
			third_max = second_max;
			second_max = arr[i];
		}
		else if(arr[i]>third_max)
			third_max = arr[i];
		if(arr[i]<first_min){
			second_min = first_min;
			first_min = arr[i];
		}
		else if(arr[i]<second_min)
			second_min = arr[i];
	}
	return max(first_max*second_max*third_max,first_max*first_min*second_min);
}

int main() {
	vector<int> arr = {-10, -10, 5, 2};
	cout<<find_max_triplet(arr)<<endl;
	cout<<find_max_triplet2(arr);
	return 0;
}
