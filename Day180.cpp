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
	int sz = s.size();
	int mid = (sz+1)/2,i=1;
	queue<int> q;
	//next three while loops reverse the first half of stack
	while(i<=mid){
		q.push(s.top());
		s.pop();
		i++;
	}
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	i = 1;
	while(i<=mid){
		q.push(s.top());
		s.pop();
		i++;
	}
	
	//merging the reverse first half stored in stack and normal second half stored in stack
	i = 1;
	if(sz%2){
	    q.push(q.front());
	    q.pop();
	    mid--;
	}
	while(i<=mid){
		q.push(s.top());
		q.push(q.front());
		q.pop();
		s.pop();
		i++;
	}
	
	//at last queue stores the interleaved elements in reversed orderd get them in stack to it become normal interleaved as required
	while(!q.empty()){
		s.push(q.front());
		q.pop();
		
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
