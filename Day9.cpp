/****************************************************************************************************************************************
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
Follow-up: Can you do this in O(N) time and constant space?
*****************************************************************************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int FindMaxSum(int arr[], int n) { 
    int incl = arr[0], excl = 0, excl_new, tmp_min=INT_MIN; 
    for (int i = 1; i < n; i++) { 
    excl_new = (incl > excl)? incl: excl; 
    incl = excl + arr[i]; 
	excl = excl_new; 
	tmp_min = max(tmp_min,arr[i]);
        
    } 
    int ans =  max(incl, excl); 
    if(ans == 0)
        return tmp_min;
    return ans;
} 


int main() { 
    int arr[] = {-5, -5, -10, -100, -10, -5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout<<FindMaxSum(arr, n)<<endl; 
    return 0; 
    } 
