/*************************************************************************************************************************************************************
This problem was asked by Microsoft.
Given an array of numbers arr and a window of size k, print out the median of each window of size k starting from the left and moving right by one position 
each time.
For example, given the following array and k = 3:
[-1, 5, 13, 8, 2, 3, 3, 1]
Your function should print out the following:
5 <- median of [-1, 5, 13]
8 <- median of [5, 13, 8]
8 <- median of [13, 8, 2]
3 <- median of [8, 2, 3]
3 <- median of [2, 3, 3]
3 <- median of [3, 3, 1]
Recall that the median of an even-sized list is the average of the two middle numbers.
*************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findMeadian(vector<int>& arr,int k){
    vector<int> tmp(arr.begin(),arr.begin()+k);
    sort(tmp.begin(),tmp.end());
    for(int i=k-1;i<arr.size();i++){
        if(k%2)
            cout<<tmp[k/2]<<" ";
        else
            cout<<(tmp[k/2]+tmp[k/2-1])/2.0<<" ";
        tmp.erase(lower_bound(tmp.begin(),tmp.end(),arr[i-k+1]));
        tmp.insert(lower_bound(tmp.begin(),tmp.end(),arr[i+1]),arr[i+1]);
    }
}


int main() {
    vector<int> arr = {-1, 5, 13, 8, 2, 3, 3, 1};
    int k = 4;
    findMeadian(arr,k);
	return 0;
}
