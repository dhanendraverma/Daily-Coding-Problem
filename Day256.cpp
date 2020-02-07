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
	
	void push(int data){
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
	
	void printList(){
		Node* temp = head;
		while(temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	
	void rearrangeList(){
		Node* prev = head;
		Node* curr = head->next;
		while(curr){
			if(prev->data>curr->data)
				swap(prev->data,curr->data);
			if(curr->next && curr->data<curr->next->data)
				swap(curr->next->data,curr->data);
			prev = curr->next;
			if(!curr->next)
				break;
			curr = curr->next->next;
		}
	}
};

int main() {
	LinkedList ll;
	ll.push(1);
	ll.push(2);
	ll.push(3);
	ll.push(4);
	ll.push(5);
	ll.printList();
	ll.rearrangeList();
	ll.printList();
	return 0;
}
