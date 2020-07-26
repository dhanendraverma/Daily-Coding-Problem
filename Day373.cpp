/***********************************************************************************************************************************************************
This problem was asked by Facebook.
Given a list of integers L, find the maximum length of a sequence of consecutive numbers that can be formed using elements from L.
For example, given L = [5, 2, 99, 3, 4, 1, 100], return 5 as we can build a sequence [1, 2, 3, 4, 5] which has length 5.
***********************************************************************************************************************************************************/



// ################################################### O(n) time ans O(n) space approach ###################################################################

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int max_conseq_len2(vector<int> arr){
    unordered_set<int> s(arr.begin(),arr.end());
    int ans = 1,curr;
    for(int i=0;i<arr.size();i++){
        if(s.find(arr[i]-1) == s.end()){
            int ele = arr[i];
            while(s.find(ele) != s.end())
                ele++;
            ans = max(ans,ele-arr[i]);
        }
    }
    return ans;
}


int main() {
    vector<int> arr = {5, 2, 99, 3, 4, 1, 100};
    cout<<max_conseq_len2(arr)<<endl;
	return 0;
}



// ################################################### O(nlogn) time ans O(1) space approach ###################################################################
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_conseq_len(vector<int> arr){
    int ans = 1, curr = 1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1]+1)
            curr += 1;
        else
            curr = 1;
        ans = max(ans,curr);
    }
    return ans;
}


int main() {
    vector<int> arr = {5, 2, 99, 3, 4, 1, 100};
    cout<<max_conseq_len(arr)<<endl;
	return 0;
}
