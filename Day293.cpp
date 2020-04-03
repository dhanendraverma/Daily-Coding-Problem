#include <iostream>
#include <vector>
using namespace std;

int lowestCost(vector<int> stones){
    int n = stones.size();
    vector<int> left(n,-1), right(n,-1),minHeight(n);
    left[0] = min(stones[0],1);
    right[n-1] = min(stones[n-1],1);
    for(int i=1;i<n;i++){
        left[i] = min(stones[i],min(i+1,left[i-1]+1));
        right[n-i-1] = min(stones[n-i-1],min(i+1,right[n-i]+1));
    }
    int maxHeight=0,max_idx;
    for(int i=0;i<n;i++){
        if(maxHeight<min(left[i],right[i])){
            maxHeight = min(left[i],right[i]);
            max_idx = i;
        }
    }
    // cout<<maxHeight<<" "<<max_idx<<endl;
    int cost=0,height=maxHeight;
    for(int i=max_idx;i>=0;i--){
        cost += stones[i]-height;
        if(height>0)
            height--;
    }
   height = maxHeight-1;
    for(int i=max_idx+1;i<n;i++){
        cost += stones[i]-height;
        if(height>0)
            height--;
    }
    return cost;
}

int main() {
    vector<int> stones = {1, 1, 3, 3, 2, 1};
    cout<<lowestCost(stones)<<endl;
	return 0;
}
