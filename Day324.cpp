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
