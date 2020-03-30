/*****************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Netflix.
Given an array of integers, determine whether it contains a Pythagorean triplet. Recall that a Pythogorean triplet (a, b, c) 
is defined by the equation a2+ b2= c2.
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPythogoreanTriplets(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        arr[i] *= arr[i];
    sort(arr.begin(),arr.end());
    for(int i=arr.size()-1;i>=2;i--){
        int l=0,r=i-1;
        while(l<r){
            if(arr[l]+arr[r]==arr[i]){
                cout<<arr[l]<<" "<<arr[r]<<" "<<arr[i]<<endl;
                break;
            }
           (arr[l] + arr[r] < arr[i]) ? l++ : r--; 
        }
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 6, 5};
    findPythogoreanTriplets(arr);
	return 0;
}
