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
