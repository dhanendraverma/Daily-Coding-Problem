/*****************************************************************************************************************************
This problem was asked by Sumo Logic.
<br>Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.
<br>An element is considered a peak if it is greater than both its left and right neighbors. 
It is guaranteed that the first and last elements are lower than all others.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int findPeaKEle(vector<int> arr){
    int n=arr.size();
    int l=0,r=arr.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if((mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid]>arr[mid+1]))
            return arr[mid];
        else if(mid>0 && arr[mid-1]>arr[mid])
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 15, 2, 23, 90, 67};
    cout<<findPeaKEle(arr)<<endl;
	return 0;
}
