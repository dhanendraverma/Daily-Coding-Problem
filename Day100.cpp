/***************************************************************************************************************************************
This problem was asked by Google.
You are in an infinite 2D grid where you can move in any of the 8 directions:
 (x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you 
can achieve it. You start from the first point.
Example:
Input: [(0, 0), (1, 1), (1, 2)]
Output: 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int min_steps(vector<pair<int,int>> points){
	int x1,y1,x2,y2,ans=0;
	for(int i=0;i<points.size()-1;i++){
		x1 = points[i].first;
		y1 = points[i].second;
		x2 = points[i+1].first;
		y2 = points[i+1].second;
		ans += max(abs(x2-x1),abs(y2-y1));
	}
	return ans;
}

int main() {
	vector<pair<int,int>> points = {{-1, -3}, {1, 4}, {-1, 5}, {-3, 10}};
	cout<<min_steps(points);
	return 0;
}
