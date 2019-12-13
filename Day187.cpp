/*************************************************************************************************************************************
This problem was asked by Google.
You are given given a list of rectangles represented by min and max x- and y-coordinates. Compute whether or not a pair of rectangles
overlap each other. If one rectangle completely covers another, it is considered overlapping.
For example, given the following rectangles:
{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
return true as the first and third rectangle overlap each other.
**************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

#define PII pair<int,int>

bool comp(vector<pair<PII,PII>> a, vector<pair<PII,PII>> b){
	if(a.first.first!=b.first.first)
		return a.first.first<b.first.first;
	else if(a.first.second!=b.first.second)
		return a.first.second>b.first.second;
	else if(a.second.first!=b.second.first)
		return a.second.first>b.second.first;
	else if(a.second.second!=b.second.second)
		return a.second.second<b.second.second;
}

bool findOverlapping(vector<pair<string,PII>> rectangles){
	vector<pair<PII,PII>> temp;
	for(int i=0;i<rectangles.size();i+=2){
		int x = rectangles[i].second.first;
		int y = rectangles[i].second.second;
		int w = rectangles[i+1].second.first;
		int h = rectangles[i+1].second.second;
		temp.push_back({x,x+w},{y,y+h});
	}
	sort(temp.begin(),temp.end(),comp);
	for(int i=0;i<temp.size()-1;i++){
		int x1 = temp[i].first.first;
		int x2 = temp[i].first.second;
		int y1 = temp[i].second.first;
		int y2 = temp[i].second.second;
		int x3 = temp[i+1].first.first;
		int x4 = temp[i+1].first.second;
		int y3 = temp[i+1].second.first;
		int y4 = temp[i+1].second.second;
		if(x1<=x3 && x2>=x4 && y1>=y3 && y2<=y4)
			return true;
	}
}

int main() {
	vector<pair<string,PII>> rectangles;
	rectangles.push_back({"top_left": {1, 4});
	rectangles.push_back({"dimensions": {3, 3});
	rectangles.push_back({"top_left": {-1, 3});
	rectangles.push_back({"dimensions": {2, 1});
	rectangles.push_back({"top_left": {0, 5});
	rectangles.push_back({"dimensions": {4, 3});
	findOverlapping(rectangles);
	return 0;
}
