/***************************************************************************************************************************************************************
This problem was asked by Pinterest.
At a party, there is a single person who everyone knows, but who does not know anyone in return (the "celebrity"). To help figure out who this is, 
you have access to an O(1) method called knows(a, b), which returns True if person a knows person b, else False.
Given a list of N people and the above operation, find a way to identify the celebrity in O(N) time.
***************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> acq = {{0, 0, 1, 0}, 
                          {0, 0, 1, 0}, 
                          {0, 0, 0, 0}, 
                          {0, 0, 1, 0}};


bool knows(int a,int b){
	return acq[a][b]==1;
}

void findCelebrity(){
	int a = 0, n = acq.size();
	int b = n-1;
	while(a<b){
		if(knows(a, b))
			a++;
		else
			b--;
	}
	for(int i=0;i<n;i++){
		if(i!=a && (!knows(i,a) && knows(a,i) )){
			cout<<"No celeberity in party."<<endl;
			return;
		}
	}
	cout<<a<<" is celebrity in party."<<endl;
}

int main() {
	findCelebrity();
	return 0;
}
