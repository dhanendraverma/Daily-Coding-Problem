/*************************************************************************************************************************************
This problem was asked by Google.
Given a linked list, sort it in O(n log n) time and constant space.
For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99.
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
		head = NULL;
	}
	
	void push(int data){
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
	}
};

Node* sortedMerge(Node* a,Node* b){
	if(!a)
		return b;
	if(!b)
		return a;
	Node* ret = NULL;
	if(a->data<=b->data){
		ret = a;
		ret->next = sortedMerge(a->next,b);
	}
	else{
		ret = b;
		ret->next = sortedMerge(a,b->next);
	}
	return ret;
}

void divideList(Node* source, Node** first, Node** second){
	Node *fast=source->next,*slow=source;
	while(fast){
		fast = fast->next;
		if(fast){
			slow = slow->next;
			fast = fast->next;
		}
		*first = source;
		*second = slow->next;
		slow->next = NULL;
	}
}


void MergeSort(Node** head){
	Node* Head = *head;
	Node *a,*b;
	if(!Head || !Head->next)
		return;
	divideList(Head,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	*head = sortedMerge(a,b);
}


int main() {
	LinkedList ll;
	ll.push(15);
	ll.push(10);
	ll.push(5);
	ll.push(20);
	ll.push(3);
	ll.push(2);
	ll.printList();
	MergeSort(&(ll.head));
	return 0;
}
