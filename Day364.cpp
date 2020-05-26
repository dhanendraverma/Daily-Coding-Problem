/******************************************************************************************************************************
This problem was asked by Facebook.
Describe an algorithm to compute the longest increasing subsequence of an array of numbers in O(n log n) time.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int>& arr){
    int n = arr.size();
    vector<int> active_lists(n);
    active_lists[0] = arr[0];
    int curr_len=1;
    for(int i=1;i<n;i++){
        auto it = lower_bound(active_lists.begin(),active_lists.begin()+curr_len,arr[i]);
        if(it-active_lists.begin()==curr_len)
            active_lists[curr_len++] = arr[i];
        else
            *it = arr[i];
    }
    return curr_len;
}

int main() {
    vector<int> arr = {2, 5, 3, 7, 11, 8, 10, 13, 6 };
    cout<<LIS(arr)<<endl;
	return 0;
}
