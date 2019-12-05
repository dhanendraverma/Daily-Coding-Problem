/**************************************************************************************************************************************
This problem was asked by Google.
Given the head of a singly linked list, swap every two nodes and return its head.
For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList{
	public:
	Node* head;
	LinkedList(){
		head = NULL;
	}
	
	void insert(int data){
		if(!head)
			head = new Node(data);
		else{
			Node* temp = new Node(data);
			temp->next = head;
			head = temp;
		}
	}
	
	void printList(){
		Node* temp = head;
		while(temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	
	Node* swapNodesRecur(Node* head){
		if(!head || !head->next)
			return head;
		Node* rem = head->next->next;
		Node* newHead = head->next;
		head->next->next = head;
		head->next = swapNodesRecur(rem);
		return newHead;
	}
	
	void swapNodes(){
		head = swapNodesRecur(head);
	}
	
	void swapNodes1(){
		Node* curr = head->next->next;
		Node* prev = head;
		head = head->next;
		head->next = prev;
		Node* next;
		while(curr && curr->next){
			prev->next= curr->next;
			prev = curr;
			next = curr->next->next;
			curr->next->next = curr; 
        	curr = next; 
		}
		prev->next = curr;
	}
};

int main() {
	LinkedList ll;
	ll.insert(2);
	ll.insert(5);
	ll.insert(6);
	ll.insert(19);
	ll.insert(4);
	ll.printList();
	ll.swapNodes();
	ll.printList();
	ll.swapNodes1();
	ll.printList();
	return 0;
}
