/******************************************************************************************************************************
This problem was asked by Microsoft.
Given an array of numbers and a number k, determine if there are three entries in the array which add up to the specified 
number k. For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool TripletsWithSum(vector<int>& arr,int k){
    for(int i=0;i<arr.size()-2;i++){
        int twoSum = k - arr[i];
	unordered_set<int> mp;
        for(int j=i+1;j<arr.size();j++){
            if(mp.find(twoSum-arr[j]) != mp.end())
                return true;
            mp.insert(arr[j]);
        }
    }
    return false;
}

int main() {
    vector<int> arr = {20, 303, 3, 4, 25};
    int k = 49;
    cout<<TripletsWithSum(arr,k)<<endl;
	return 0;
}
