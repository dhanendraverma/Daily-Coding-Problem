/*************************************************************************************************************************************************************
This problem was asked by Amazon.
Given a sorted array arr of distinct integers, return the lowest index i for which arr[i] == i. Return null if there is no such index.
For example, given the array [-5, -3, 2, 3], return 2 since arr[2] == 2. Even though arr[3] == 3, we return 2 since it's the lowest index.
*************************************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

int find_idx(vector<int>& arr){
    int start = 0,end = arr.size()-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]<mid)
            start = mid+1;
        else{
            if(mid==arr[mid])
                ans = mid;
            end = mid-1;
        }
    }
    return ans;
}


int main() {
    vector<int> arr = {-10,-4,2,3, 4, 7, 9, 12, 13};
    cout<<find_idx(arr)<<endl;
	return 0;
}
