/**************************************************************************************************************************************
This problem was asked by Amazon.
Implement a stack API using only a heap. A stack implements the following methods:
push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)
Recall that a heap has the following operations:
push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
***************************************************************************************************************************************/



#include <iostream>
#include <queue>
using namespace std;

class Stack{
	int count;
	priority_queue<pair<int,int>> q;
	public:
	Stack(){
		this->count = 0;
	}
	
	void push(int data){
		count++;
		q.push({count,data});
	}
	
	int pop(){
		if(q.empty()){
			cout<<"Stack is empty"<<endl;
			exit(0);
		}
		count--;
		int d = q.top().second;
		q.pop();
		return d;
	}
};

int main() {
	Stack s;
	s.push(3);
	s.push(8);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	return 0;
}
