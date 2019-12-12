/*****************************************************************************************************************************************
This problem was asked by Amazon.
Given n numbers, find the greatest common denominator between them.
For example, given the numbers [42, 56, 14], return 14.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

int findGCD(vector<int> nums){
	int ans = nums[0];
	for(int i=1;i<nums.size();i++){
		ans = gcd(nums[i],ans);
		if(ans==1)
			return ans;
	}
	return ans;
}

int main() {
	vector<int> nums = {14,56,42};
	cout<<findGCD(nums)<<endl;
	return 0;
}
