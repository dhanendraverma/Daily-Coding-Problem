/**************************************************************************************************************************************
This problem was asked by Google.
Given a stack of N elements, interleave the first half of the stack with the second half reversed using only one other queue. This 
should be done in-place.
Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.
For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3]. If the stack is [1, 2, 3, 4], it should become
[1, 4, 2, 3].
Hint: Try working backwards from the end state.

Upgrade to premium and get in-depth solutions to every probl
**************************************************************************************************************************************/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void revInterLeave(stack<int>& s){
	int cnt = s.size();
	queue<int> temp;
	for(int i=1;i<cnt;i++){
		while(s.size()>i){
			temp.push(s.top());
			s.pop();
		}
		while(!temp.empty()){
			s.push(temp.front());
			temp.pop();
		}
	}
}


int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	revInterLeave(s);
	int cnt = s.size();
	for(int i=0;i<cnt;i++){
		cout<<s.top();
		s.pop();
	}
	return 0;
}
