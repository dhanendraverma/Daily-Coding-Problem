/*****************************************************************************************************************************************
This problem was asked by Google.
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
In this example, assume nodes with the same value are the exact same node objects.
Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
******************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
};

int findintersection(Node* head1, Node* head2){
	set<Node*> visited;
	while(head1){
		visited.insert(head1);
		head1 = head1->next;
		
	}
	
	while(head2){
		if(visited.find(head2)!=visited.end())
			return head2->data;
		head2 = head2->next;
	}
	return -1;
}

int main() {
	// your code goes here
	Node* newNode;
	
	Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
    
    cout<<"intersection point of lists "<<findintersection(head1,head2)<<endl;
	return 0;
}
