/*****************************************************************************************************************************
This problem was asked by Nvidia.
You are given a list of N points (x1, y1), (x2, y2), ..., (xN, yN) representing a polygon. You can assume these points are 
given in order; that is, you can construct the polygon by connecting point 1 to point 2, point 2 to point 3, and so on,
finally looping around to connect point N to point 1.
Determine if a new point p lies inside this polygon. (If p is on the boundary of the polygon, you should return False).
*****************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool onSegment(pair<int,int> p, pair<int,int> q, pair<int,int> r){
	return (q.first<=max(p.first,r.first) && q.first>=min(p.first,p.first) && 
			q.second<=max(p.second,r.second) && q.second>=min(p.second,p.second));
}

int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r){
	int o = ((q.second-p.second)*(r.first-q.first)-(q.first-p.first)*(r.second-q.second));
	if(o==0)
		return 0;
	return o>0?1:2;
}

bool doIntersect(pair<int,int> p1, pair<int,int> q1, pair<int,int> p2, pair<int,int> q2){
	int o1 = orientation(p1,q1,p2);
	int o2 = orientation(p1,q1,q2);
	int o3 = orientation(p2,q2,p1);
	int o4 = orientation(p2,q2,q1);
	if(o1!=o2 && o3!=o4)
		return true;
	if(o1==0 && onSegment(p1,p2,q1))
		return true;
	else if(o2==0 && onSegment(p1,q2,q1))
		return true;
	else if(o3==0 && onSegment(p2,p1,q2))
		return true;
	else if(o4==0 && onSegment(p2,q1,q2))
		return true;
	return false;
}

bool insidePolygon(vector<pair<int,int>>& polygon, pair<int,int> p){
	int n = polygon.size();
	if(n<3)
		return false;
	pair<int,int> p1 = {INT_MAX,p.second};
	int count=0, i=0, temp = n;
	while(temp--){
		if(doIntersect(polygon[i],polygon[(i+1)%n],p,p1))
			count++;
		i++;
	}
	return count&1;
}

int main() {
	vector<pair<int,int>> polygon = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
	pair<int,int> p = {10,10};
	cout<<insidePolygon(polygon,p)<<endl;
	return 0;
}
