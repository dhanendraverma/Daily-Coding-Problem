/*****************************************************************************************************************************
This problem was asked by PagerDuty.
Given a positive integer N, find the smallest number of steps it will take to reach 1.
There are two kinds of permitted steps:
You may decrement N to N - 1.
If a * b = N, you may decrement N to the larger of a and b.
For example, given 100, you can reach 1 in five steps with the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1.
******************************************************************************************************************************/

#include <iostream>
#include <queue>
#include <set>
using namespace std;

int minStepsToOne(int N){
    queue<pair<int,int>> q;
    q.push({N,0});
    set<int> visited;
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        if(curr.first==1)
            return curr.second;
        if(visited.find(curr.first-1) == visited.end())
            visited.insert(curr.first-1);
        for(int i=2;i*i<=curr.first;i++){
            if(curr.first%i==0 && visited.find(curr.first/i) == visited.end()){
                q.push({curr.first/i,curr.second+1});
                visited.insert(curr.first/i);
            }
        }
    }
}

int main() {
    int N = 16;
    cout<<minStepsToOne(N)<<endl;
	return 0;
}
