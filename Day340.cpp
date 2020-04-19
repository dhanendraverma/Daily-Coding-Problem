/******************************************************************************************************************************
This problem was asked by Google.
Given a set of points (x, y) on a 2D cartesian plane, find the two closest points. For example, given the points 
[(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)], return [(-1, -1), (1, 1)].
******************************************************************************************************************************/

#include <bits/stdc++.h> 
using namespace std; 

class Point{ 
	public: 
	int x, y; 
}; 

Point ans1, ans2;


int compareX(const void* a, const void* b){ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

int compareY(const void* a, const void* b){ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 

float dist(Point p1, Point p2){ 
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)); 
} 

float bruteForce(Point P[], int n){ 
	float minDist = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j])<minDist)
				min = dist(P[i], P[j]); 
	return min; 
} 

float min(float x, float y){ 
	return (x < y)? x : y; 
} 

float stripClosest(Point strip[], int size, float d) 
{ 
	float min = d; 
	qsort(strip, size, sizeof(Point), compareY); 
	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min){ 
				min = dist(strip[i], strip[j]);
				ans1 = strip[i];
				ans2 = strip[j];
			}

	return min; 
} 

float closestUtil(Point P[], int n) { 
	if (n <= 3) 
		return bruteForce(P, n); 
	int mid = n/2; 
	Point midPoint = P[mid]; 
	float dl = closestUtil(P, mid); 
	float dr = closestUtil(P + mid, n - mid); 
	float d = min(dl, dr); 
	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(P[i].x - midPoint.x) < d) 
			strip[j] = P[i], j++; 
	return min(d, stripClosest(strip, j, d) ); 
} 


float closest(Point P[], int n){ 
	qsort(P, n, sizeof(Point), compareX); 
	return closestUtil(P, n); 
} 


int main(){ 
	Point P[] = {{1, 1}, {-1, -1}, {3, 4}, {6, 1}, {-1, -6}, {-4, -3}}; 
	int n = sizeof(P) / sizeof(P[0]); 
	cout<<closest(P, n)<<endl;; 
	cout<<ans1.x<<" "<<ans1.y<<endl;
	cout<<ans2.x<<" "<<ans2.y<<endl;
	return 0; 
} 
