/**************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Google.
Given the head of a singly linked list, reverse it in-place.
***************************************************************************************************************************************/

#include <iostream> 
using namespace std; 

class Node { 
	public:
	int data; 
	struct Node* next; 
	Node(int data) 
	{ 
		this->data = data; 
		next = NULL; 
	} 
}; 

class LinkedList { 
	public:
	Node* head; 
	LinkedList() 
	{ 
		head = NULL; 
	} 
	
	void reverse() 
	{ 
		Node* curr= head; 
		Node *prev = NULL, *next = NULL;
		while (curr) { 
			next = curr->next; 
			curr->next = prev; 
			prev = curr; 
			curr = next; 
		} 
		head = prev; 
	} 
	void print() 
	{ 
		struct Node* temp = head; 
		while (temp) { 
			cout << temp->data << " "; 
			temp = temp->next; 
		} 
	} 

	void push(int data) 
	{ 
		Node* temp = new Node(data); 
		temp->next = head; 
		head = temp; 
	} 
}; 


int main() 
{ 
	LinkedList ll; 
	ll.push(32); 
	ll.push(12); 
	ll.push(56); 
	ll.push(14);
	ll.push(67);
	ll.push(38);
	ll.print(); 
	cout<<endl;
	ll.reverse(); 
	ll.print(); 
	return 0; 
} 
