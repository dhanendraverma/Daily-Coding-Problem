/**************************************************************************************************************************************
This question was asked by Snapchat.
Given the head to a singly linked list, where each node also has a “random” pointer that points to anywhere in the linked list, deep 
clone the list.
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* random;
	Node(int data){
		this->data = data;
		next = NULL;
		random = NULL;
	}
};

void printList(Node *start) 
{ 
    Node *temp = start; 
    while(temp) 
    { 
    	cout<<"Data = "<<temp->data<<", Random  = "<<temp->random->data<<endl; 
        temp = temp->next; 
    } 
} 
	
Node* clone(Node* start){
	Node *curr = start, *temp;
	while(curr){
		temp = curr->next;
		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}
	curr = start;
	while(curr){
		if(curr->next)
			curr->next->random = curr->random?curr->random->next:curr->random;
		curr = curr->next?curr->next->next:curr->next;
	}
	Node *originalList = start, *copyList = start->next;
	temp = copyList;
	while(originalList && copyList){
		originalList->next = originalList->next?originalList->next->next:originalList->next;
		copyList->next = copyList->next?copyList->next->next:copyList->next;
		originalList = originalList->next;
		copyList = copyList->next;
	}
	return temp;
}


int main() {
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
  
    cout<<"Original list : "<<endl; 
    printList(start); 
    cout<<endl<<"Cloned list : "<<endl; 
    Node *cloned_list = clone(start); 
    printList(cloned_list); 
	return 0;
}
