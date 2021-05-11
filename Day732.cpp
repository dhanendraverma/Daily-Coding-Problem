
/*****************************************************************************************************************************
This problem was asked by Glassdoor.
An imminent hurricane threatens the coastal town of Codeville. If at most two people can fit in a rescue boat, 
and the maximum weight limit for a given boat is k, determine how many boats will be needed to save everyone.
For example, given a population with weights [100, 200, 150, 80] and a boat limit of 200, the smallest number of boats 
required will be three.
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int noOfBoats(vector<int> weights,int limit){
    sort(weights.begin(), weights.end());
    int l=0,r=weights.size()-1,count=0;
    while(l<r){
        if(weights[l]+weights[r]<=limit)
            l++;
        count++;
        r--;
    }
    if(l==r)
        count++;
    return count;
}

int main() {
    vector<int> weights = {100, 200, 150, 80};
    int limit = 200;
    cout<<noOfBoats(weights,limit)<<endl;
	return 0;
}
