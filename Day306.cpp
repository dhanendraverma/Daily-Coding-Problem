/*****************************************************************************************************************************
This problem was asked by Palantir.
You are given a list of N numbers, in which each number is located at most k places away from its sorted position. 
For example, if k = 1, a given element at index 4 might end up at indices 3, 4, or 5.
Come up with an algorithm that sorts this list in O(N log k) time.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortArr(vector<int>& arr, int k){
    priority_queue<int,vector<int>,greater<int>> pq(arr.begin(), arr.begin()+k+1);
    int curr_idx=0;
    for(int i=k+1;i<arr.size();i++){
        arr[curr_idx++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        arr[curr_idx++] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> arr = { 2, 6, 3, 12, 56, 8 };
    int k = 3;
    sortArr(arr,k);
    for(auto i:arr)
        cout<<i<<" ";
	return 0;
}
