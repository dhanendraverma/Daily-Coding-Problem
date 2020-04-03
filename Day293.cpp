/*****************************************************************************************************************************
This problem was asked by Uber.
You have N stones in a row, and would like to create from them a pyramid. This pyramid should be constructed such that the 
height of each stone increases by one until reaching the tallest stone, after which the heights decrease by one. 
In addition, the start and end stones of the pyramid should each be one stone high.
You can change the height of any stone by paying a cost of 1 unit to lower its height by 1, as many times as necessary. 
Given this information, determine the lowest cost method to produce this pyramid.
For example, given the stones [1, 1, 3, 3, 2, 1], the optimal solution is to pay 2 to create [0, 1, 2, 3, 2, 1].
*****************************************************************************************************************************/

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
