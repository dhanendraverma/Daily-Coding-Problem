/**************************************************************************************************************************************
This problem was asked by Apple.
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: 
enqueue, which inserts an element into the queue, and dequeue, which removes it.
***************************************************************************************************************************************/


#include <iostream>
#include <stack>
using namespace std;

class Queue{
	stack<int> s1,s2;
	public:
		void enQueue(int data){
			s1.push(data);
		}
		
		int  deQueue(){
			if(s2.empty() && s1.empty()){
				cout<<"Queue is empty";
				exit(0);
			}
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			int x = s2.top();
			s2.pop();
			return x;
		}
};


int main() {
	stack<int> s1,s2;
	Queue Q;
	Q.enQueue(2);
	Q.enQueue(5);
	cout<<Q.deQueue()<<endl;
	cout<<Q.deQueue()<<endl;
	cout<<Q.deQueue()<<endl;
	return 0;
}
