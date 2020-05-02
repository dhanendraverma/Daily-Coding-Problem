/******************************************************************************************************************************
This problem was asked by Airbnb.
You are given an array X of floating-point numbers x1, x2, ... xn. These can be rounded up or down to create a corresponding 
array Y of integers y1, y2, ... yn.
Write an algorithm that finds an appropriate Y array with the following properties:
The rounded sums of both arrays should be equal.
The absolute pairwise difference between elements is minimized. In other words, |x1- y1| + |x2- y2| + ... + |xn- yn| should be
as small as possible.
For example, suppose your input is [1.3, 2.3, 4.4]. In this case you cannot do better than [1, 2, 5], which has an absolute
difference of |1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1.
*****************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

bool comp(pair<int,float> a, pair<int,float> b){
    return (a.first-a.second)<(b.first-b.second);
}


vector<int> minRoundingError(vector<float> arr){
    vector<pair<int,float>> Y;
    for(auto x:arr)
        Y.push_back({floor(x),x});
    int floor_sum=0;
    for(auto y:Y)
        floor_sum += y.second;
    int extra = round(accumulate(arr.begin(),arr.end(),0.0)-floor_sum);
    sort(Y.begin(),Y.end(),comp);
    vector<int> ans;
    for(auto y:Y)
        ans.push_back(y.first);
    int i=0;
    while(extra--){
        ans[i++] += 1;
    }
    return ans;
}

int main() {
    vector<float> arr = {30.9, 2.4, 3.9};
    vector<int> Y = minRoundingError(arr);
    for(auto y:Y)
        cout<<y<<" ";
	return 0;
}
