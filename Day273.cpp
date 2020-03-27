/*****************************************************************************************************************************
This problem was asked by Apple.
A fixed point in an array is an element whose value is equal to its index. Given a sorted array of distinct elements, 
return a fixed point, if one exists. Otherwise, return False.
For example, given [-6, 0, 2, 40], you should return 2. Given [1, 5, 7, 8], you should return False.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int findFixedPoint(vector<int>& arr){
    int l=0,r = arr.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]==mid)
            return mid;
        if(arr[mid]<mid)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

int main() {
    vector<int> arr = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    cout<<findFixedPoint(arr)<<endl;
	return 0;
}
