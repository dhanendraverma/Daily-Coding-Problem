/**************************************************************************************************************************************
This problem was asked by Google.
Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i, j) satisfies
either i % j = 0 or j % i = 0.
For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. Given [1, 3, 6, 24], return [1, 3, 6, 24].
**************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> nums) {
    vector<int> result;
    if(nums.size()==0)
        return result;
    sort(nums.begin(),nums.end());
    vector<int> t(nums.size(),1);
    vector<int> index(nums.size(),-1);
    int max=0;
    int maxIndex=-1;
    for(int i=0; i<t.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(nums[i]%nums[j]==0 && t[j]+1>t[i]){
                t[i]=t[j]+1;
                index[i]=j;
            }
        }
        if(max<t[i]){
            max=t[i];
            maxIndex=i;
        }
    }
    int i=maxIndex;
    while(i>=0){
        result.push_back(nums[i]);
        i=index[i];
    }
    return result;
}

int main() {
	vector<int> arr = {1, 2, 4, 5, 20};
	vector<int> t =largestDivisibleSubset(arr);
	for(auto i:t)
		cout<<i<<" ";
	return 0;
}
