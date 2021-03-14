/***************************************************************************************************************************************************************
This problem was asked by Amazon.
Implement a stack API using only a heap. A stack implements the following methods:
    push(item), which adds an element to the stack
    pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)
Recall that a heap has the following operations:
    push(item), which adds a new key to the heap
    pop(), which removes and returns the max value of the heap
***************************************************************************************************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

class Stack{
	public:
		priority_queue<pair<int,int>> pq;
		int order ;
		Stack():order(0){};
		
		void push(int data){
			order++;
			pq.push({order,data});
		}
		
		int pop(){
			if(pq.empty()){
				cout<<"Stack is empty."<<endl;
				exit(0);
			}
			int ele = pq.top().second;
			pq.pop();
			return ele;
		}
};

int main() {
	Stack st;
	st.push(6);
	st.push(7);
	st.push(8);
	st.push(10);
	st.push(11);
	while(1)
		cout<<st.pop()<<" "<<endl;
	return 0;
}
