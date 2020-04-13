/*****************************************************************************************************************************
This problem was asked by Amazon.
Consider the following scenario: there are N mice and N holes placed at integer points along a line. Given this, 
find a method that maps mice to holes such that the largest number of steps any mouse takes is minimized.
Each move consists of moving one mouse one unit to the left or right, and only one mouse can fit inside each hole.
For example, suppose the mice are positioned at [1, 4, 9, 15], and the holes are located at [10, -5, 0, 16]. In this case, 
the best pairing would require us to send the mouse at 1 to the hole at -5, so our function should return 6.
******************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSteps(vector<int>& mice, vector<int>& holes){
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());
    int min_steps = 0;
    for(int i=0;i<mice.size();i++){
        if(abs(mice[i]-holes[i]) > min_steps)
            min_steps = (mice[i] - holes[i]);
    }
    return min_steps;
}

int main() {
    vector<int> mice = {1, 4, 9, 15};
    vector<int> holes = {10, -5, 0, 16};
    cout<<minSteps(mice, holes)<<endl;
	return 0;
}
