/*****************************************************************************************************************************
This problem was asked by Spotify.
You are the technical director of WSPT radio, serving listeners nationwide. For simplicity's sake we can consider each 
listener to live along a horizontal line stretching from 0 (west) to 1000 (east).
Given a list of N listeners, and a list of M radio towers, each placed at various locations along this line, determine 
what the minimum broadcast range would have to be in order for each listener's home to be covered.
For example, suppose listeners = [1, 5, 11, 20], and towers = [4, 8, 15]. In this case the minimum range would be 5, 
since that would be required for the tower at position 15 to reach the listener at position 20.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minBroadcastRange(vector<int>& listners, vector<int>& towers){
    sort(listners.begin(), listners.end());
    sort(towers.begin(), towers.end());
    int min_range = 0, t_idx=0;
    for(auto l:listners){
        int dist = abs(l - towers[t_idx]);
        for(int i=t_idx+1;i<towers.size();i++){
            if(abs(l - towers[i])>dist)
                break;
            t_idx = i;
            dist = abs(l - towers[t_idx]);
        }
        // cout<<dist<<" "<<l<<endl;
        min_range = max(dist,min_range);
    }
    return min_range;
}

int main() {
    vector<int> listners = {1, 5, 11, 20};
    vector<int> towers = {4, 8, 15};
    cout<<minBroadcastRange(listners,towers)<<endl;
	return 0;
}
