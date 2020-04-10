/******************************************************************************************************************************
This problem was asked by Snapchat.
You are given an array of length N, where each element i represents the number of ways we can produce i units of change. 
For example, [1, 0, 1, 1, 2] would indicate that there is only one way to make 0, 2, or 3 units, and two ways of making 4 
units.
Given such an array, determine the denominations that must be in use. In the case above, for example, there must be coins
with value 2, 3, and 4.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getDenominations(vector<int> ways){
    vector<int> res;
    int n = ways.size();
    if(n==0 || ways[1]>1){
        cout<<"Not possible"<<endl;
        return {-1};
    }
    for(int i=2;i<n;i++){
        int w = 0;
        for(int j=0;j<res.size();j++)
            w += ways[i-res[j]];
        if(w == ways[i]-1)
            res.push_back(i);
        else if(w != ways[i]){
            cout<<"Not possible"<<endl;
            return {-1};
        }
    }
    return res;
}

int main() {
    vector<int> ways = {1, 0, 1, 1, 2};
    vector<int> denominations = getDenominations(ways);
    for(auto d:denominations)
        cout<<d<<" ";
	return 0;
}
