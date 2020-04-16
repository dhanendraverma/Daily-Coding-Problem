/******************************************************************************************************************************
This problem was asked by Twitter.
The 24 game is played as follows. You are given a list of four integers, each between 1 and 9, in a fixed order.
By placing the operators +, -, *, and / between the numbers, and grouping them with parentheses, 
determine whether it is possible to reach the value 24.
For example, given the input [5, 2, 7, 8], you should return True, since (5 * 2 - 7) * 8 = 24.
Write a function that plays the 24 game.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool dfs(vector<double>& nums){
    if(nums.size()==1)
        return fabs(nums[0]-24)<1e-8;
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            vector<double> tmp;
            for(int k=0;k<nums.size();k++)
                if(k!=i && k!=j) 
                    tmp.push_back(nums[k]);
            tmp.push_back(nums[i]+nums[j]);
            if(dfs(tmp)) return true;
            tmp.back() = nums[i] * nums[j];
            if(dfs(tmp)) return true;
            tmp.back() = nums[i] - nums[j];
            if(dfs(tmp)) return true;
            tmp.back() = nums[j] - nums[i];
            if(dfs(tmp)) return true;
            tmp.back() = nums[j]/nums[i];
            if(dfs(tmp)) return true;
            tmp.back() = nums[i]/nums[j];
            if(dfs(tmp)) return true;
        }
    }
    return false;
}

bool play24Game(vector<int>& input){
    vector<double> tmp(input.begin(),input.end());
    return dfs(tmp);
}

int main() {
    vector<int> input = {5, 2, 7, 8};
    cout<<play24Game(input)<<endl;
	return 0;
}
