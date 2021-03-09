/*************************************************************************************************************************************************************
This question was asked by Snapchat.
Given the head to a singly linked list, where each node also has a “random” pointer that points to anywhere in the linked list, deep clone the list.
*************************************************************************************************************************************************************/

#include <iostream> 
using namespace std; 

class Node { 
	public:
		int data; 
		Node *next, *random; 
		Node(int data) 
		{ 
			this->data = data; 
			this->next = NULL;
			this->random = NULL;
		} 
}; 


Node* cloneList(Node* head){
	Node *cloneHead = NULL, *curr = head, *temp;
	while(curr){
		temp = curr->next;
		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}
	
	curr = head;
	while(curr){
		if(curr->next)
			curr->next->random = curr->random?curr->random->next:NULL;
		curr = curr->next?curr->next->next:NULL;
	}
	temp = cloneHead = head->next;
	curr = head;
	while(curr){
		curr->next = curr->next?curr->next->next:curr->next;
		cloneHead->next = cloneHead->next?cloneHead->next->next:cloneHead->next;
		curr = curr->next;
		cloneHead = cloneHead->next;
	}
	return temp;
}

void printList(Node* head){
	while(head){ 
		cout <<head->data << " "; 
		head = head->next; 
	}
	cout<<endl;
} 


int main(){ 
	Node* start = new Node(1); 
    start->next = new Node(2); 
    start->next->next = new Node(3); 
    start->next->next->next = new Node(4); 
    start->next->next->next->next = new Node(5); 
    start->random = start->next->next; 
    start->next->random = start; 
    start->next->next->random = start->next->next->next->next; 
    start->next->next->next->random = start->next->next->next->next; 
    start->next->next->next->next->random = start->next; 
    printList(start);
    Node* cloneHead = cloneList(start); 
    printList(cloneHead);
	return 0; 
} 
