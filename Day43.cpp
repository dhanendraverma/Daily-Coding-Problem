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
#include <iostream>
#include <stack>
#include <climits>
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
			Node* newnode = new Node();
			if(head==NULL)
				mx = key;
			if(key>mx){
				newnode->data = 2*key - mx;
				mx = key;
			}
			else
				newnode->data = key;
			cout<<mx<<" "<<newnode->data<<endl;
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
		 	if(key>mx)
		 	{
		 		int temp  = mx;
		 		mx = 2*mx-key;
		 		return temp;
		 		
		 	}
		 		
		 	return key;
			
		}
		int Max(){
			return mx;
		}

};

int main() {
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
