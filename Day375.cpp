/*************************************************************************************************************************************************************
This problem was asked by Google.
The h-index is a metric used to measure the impact and productivity of a scientist or researcher.
A scientist has index h if h of their N papers have at least h citations each, and the other N - h papers have no more than h citations each. If there are
multiple possible values for h, the maximum value is used.
Given an array of natural numbers, with each value representing the number of citations of a researcher's paper, return the h-index of that researcher.
For example, if the array was:
[4, 0, 0, 2, 3]
This means the researcher has 5 papers with 4, 1, 0, 2, and 3 citations respectively. The h-index for this researcher is 2, since they have 2 papers with 
at least 2 citations and the remaining 3 papers have no more than 2 citations.
*************************************************************************************************************************************************************/



// ######################################## Time complexity O(n) and Space complexity O(n)  ########################################### 
#include <iostream>
#include <vector>
using namespace std;

int h_index2(vector<int>& arr){
    int n = arr.size();
    vector<int> cnt(n+1,0);
    for(auto citation:arr){
        if(citation>n)
            cnt[n]++;
        else
            cnt[citation]++;
    }
    int sum = 0;
    for(int i=n;i>=0;i--){
        sum += cnt[i];
        if(sum>=i)
            return i;
    }
    return 0;
}


int main() {
    vector<int> arr = {3,0,6,1,5};
    cout<<h_index2(arr)<<endl;
	return 0;
}



// ######################################## Time complexity O(nlogn) and Space complexity O(1)  ########################################### 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h_index(vector<int>& arr){
    sort(arr.begin(),arr.end(),greater<int>());
    int l=0,r=arr.size();
    while(l<r){
        int mid = l+(r-l)/2;
        if(arr[mid]>=mid+1)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}


int main() {
    vector<int> arr = {4, 1, 0, 2, 3};
    cout<<h_index(arr)<<endl;
	return 0;
}
