/*****************************************************************************************************************************
This problem was asked by VMware.
The skyline of a city is composed of several buildings of various widths and heights, possibly overlapping one another when 
viewed from a distance. We can represent the buildings using an array of (left, right, height) tuples, which tell us where on
an imaginary x-axis a building begins and ends, and how tall it is. The skyline itself can be described by a list of 
(x, height) tuples, giving the locations at which the height visible to a distant observer changes, and each new height.
Given an array of buildings as described above, create a function that returns the skyline.
For example, suppose the input consists of the buildings [(0, 15, 3), (4, 11, 5), (19, 23, 4)]. In aggregate, these buildings 
would create a skyline that looks like the one below.
*****************************************************************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool comp(vector<int> a,vector<int> b){
    return a[0]<b[0];
}

vector<pair<int,int>> findSkyLine(vector<vector<int>> buildingHeights){
    vector<vector<int>> buildingPoints;
    for(auto height:buildingHeights){
        buildingPoints.push_back({height[0],height[2],1});
        buildingPoints.push_back({height[1],height[2],0});
    }
    sort(buildingPoints.begin(),buildingPoints.end(),comp);
    map<int,int> pq;
    pq[0] = 1;
    int prevHeight = 0;
    vector<pair<int,int>> skyline;
    for(auto point:buildingPoints){
        if(point[2])//if it's start of the buildingPoints
            pq[point[1]]++;
        else{
            pq[point[1]]--;
            if(pq[point[1]]==0)
                pq.erase(point[1]);
        }
        int currMaxHeight = pq.rbegin()->first;
        if(prevHeight!=currMaxHeight){
            skyline.push_back({point[0],currMaxHeight});
            prevHeight = currMaxHeight;
        }
    }
    return skyline;
    
}

int main() {
    vector<vector<int>> buildingHeights = {{0, 15, 3}, {4, 11, 5}, {19, 23, 4}};
    vector<pair<int,int>> skyline = findSkyLine(buildingHeights);
    for(auto sl:skyline)
        cout<<sl.first<<" "<<sl.second<<endl;
	return 0;
}
