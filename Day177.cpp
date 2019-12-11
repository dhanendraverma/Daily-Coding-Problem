/**************************************************************************************************************************************
This problem was asked by Airbnb.
Given a linked list and a positive integer k, rotate the list to the right by k places.
For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.
Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2.
**************************************************************************************************************************************/

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
		this->head = NULL;
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
	
	void rotateList(int k){
		Node* temp = head;
		int count =1;
		while(temp->next){
			temp = temp->next;
			count++;
		}
		if(k>count)
			k = k%count;
		 k = count-k;
		if(k!=0 || k!=count){
			Node* curr = head;
			k--;
			while(k--)
				curr = curr->next;
			// cout<<curr->data<<endl;
			// cout<<temp->data<<endl;
			temp->next = head;
			head = curr->next;
			curr->next = NULL;
		}
	}
};

int main() {
	LinkedList ll;
	int k =2;
	ll.insert(5);
	ll.insert(4);
	ll.insert(3);
	ll.insert(2);
	ll.insert(1);
	ll.printList();
	ll.rotateList(k);
	ll.printList();
	return 0;
}
