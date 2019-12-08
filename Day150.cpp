#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

float distance(pair<int,int> X,pair<int,int> Y){
	  return sqrt(pow(Y.first - X.first, 2) +  
                pow(Y.second - Y.second, 2) * 1.0);
}

struct Point2fBarycenterComparator {
    explicit Point2fBarycenterComparator(pair<int,int> central) 
    : central(central) {}
    bool operator ()(pair<int,int> const& a, pair<int,int> const& b) const {
        float distanceA = distance(a, central);
        float distanceB = distance(b, central);
        return distanceA < distanceB;
    }
    pair<int,int> central;
};




int main() {
	std::vector<pair<int,int>> vec = {{0, 0}, {5, 4}, {3, 1}};
	pair<int,int> barycenter = {10,2};
	sort(vec.begin(), vec.end(), Point2fBarycenterComparator(barycenter));
	for(auto i: vec)
		cout<<i.first<<" "<<i.second<<endl;
	return 0;
}
