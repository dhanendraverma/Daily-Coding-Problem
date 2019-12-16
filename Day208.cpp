/**************************************************************************************************************************************
This problem was asked by LinkedIn.
Given a linked list of numbers and a pivot k, partition the linked list so that all nodes less than k come before nodes greater than or
equal to k. 
For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3, the solution could be 1 -> 0 -> 5 -> 8 -> 3.
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		next = NULL;
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
};

Node* partitionList(Node* head,int k){
	Node *Shead = NULL, *Slast = NULL;
	Node *Ghead = NULL, *Glast = NULL;
	Node *Ehead = NULL, *Elast = NULL;
	while(head){
		if(head->data==k){
			if(Ehead == NULL)
				Ehead = Elast = head;
			else
			{
				Elast->next = head;
				Elast = Elast->next;
			}
		}
		else if(head->data<k){
			if(Shead==NULL)
				Shead = Slast = head;
			else{
				Slast->next = head;
				Slast = Slast->next;
			}
		}
		else{
			if(Ghead==NULL)
				Ghead = Glast = head;
			else{
				Glast->next = head;
				Glast = Glast->next;
			}
		}
		head = head->next;
	}
	if(Glast)
		Glast->next = NULL;
	if(!Shead){
		if(!Ehead)
			return Ghead;
		Elast->next = Ghead;
		return Ehead;
	}
	if(!Ehead){
		Slast->next = Ghead;
		return Shead;
	}
	Slast->next = Ehead;
	Elast->next = Ghead;
	return Shead;
}


int main() {
	LinkedList ll;
	ll.insert(50);
	ll.insert(2);
	ll.insert(30);
	ll.insert(5);
	ll.insert(4);
	ll.insert(10);
	ll.printList();
	int k = 3;
	ll.head = partitionList(ll.head,k);
	ll.printList();
	return 0;
}
