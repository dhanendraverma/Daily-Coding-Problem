/**************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Amazon.
Implement a stack that has the following methods:
push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an
error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or
return null.
Each method should run in constant time.
***************************************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Stack{
	public:
		struct Node{
		int data;
	 	Node* next;
			
		};
		struct Node* head=NULL;
		int mx = INT_MIN;
		void push(int key){
			mx = max(mx,key);
	
			Node* newnode = new Node();
			newnode->data = key;
			newnode->next = head;
			head = newnode;
			
		}
		
		int pop(){
		 	if(!head)
		 		return NULL;
		 	Node* temp = head;
		 	head = head->next;
		 	int key = temp->data;
		 	free(temp);
		 	if(key==mx){
		 		mx = INT_MIN;
		 		Node* temp = head;
		 		while(temp){
		 			mx = max(mx,temp->data);
		 			// cout<<"mx"<<mx<<endl;
		 			temp = temp->next;
		 		}
		 	}
		 	return key;
			
		}
		int Max(){
			return mx;
		}

};

int main() {
	// your code goes here
	Stack s;
	s.push(2);
	s.push(10);
	s.push(45);
	s.push(67);
	s.push(1);
	s.push(76);
	cout<<s.pop()<<endl;
	cout<<s.Max()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.Max()<<endl;
	cout<<s.pop()<<endl;
	
	return 0;
}
