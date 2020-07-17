/*******************************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.

This problem was asked by Postmates.

The “active time” of a courier is the time between the pickup and dropoff of a delivery. Given a set of data formatted like the following:

(delivery id, timestamp, pickup/dropoff)
Calculate the total active time in seconds. A courier can pick up multiple orders before dropping them off. The timestamp is in unix epoch seconds.

For example, if the input is the following:

(1, 1573280047, 'pickup')
(1, 1570320725, 'dropoff')
(2, 1570321092, 'pickup')
(3, 1570321212, 'pickup')
(3, 1570322352, 'dropoff')
(2, 1570323012, 'dropoff')
The total active time would be 1260 seconds.
********************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int total_active_time(vector<vector<int>>& inp){
    int total = 0;
    map<int,int> mp;
    for(int i=0;i<inp.size();i++){
        if(inp[i][2] == 1){
            total += (inp[i][1]-mp[inp[i][0]]);
            mp.erase(inp[i][0]);
        }
        else
            mp[inp[i][0]] = inp[i][1];
    }
    return total;
}



int main() {
    int n;
    cin>>n;
    vector<vector<int>> inp;
    int id,sec;
    string pd;
    while(n--){
        cin>>id>>sec>>pd;
        if(pd == "pickup"){
            inp.push_back({id,sec,0});
        }
        else
            inp.push_back({id,sec,1});
    }
    cout<<total_active_time(inp)<<endl;
	return 0;
}
