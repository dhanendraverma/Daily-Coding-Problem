/*****************************************************************************************************************************************
This problem was asked by Google.
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
In this example, assume nodes with the same value are the exact same node objects.
Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
******************************************************************************************************************************************/

#include <iostream>
#include <unordered_set>
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

int findIntersectionHash(Node* head1, Node* head2){
	Node *list1 = head1, *list2 = head2;
	unordered_set<Node*> visited;
	
	while(list1){
		// cout<<list1->data<<" ";
		visited.insert(list1);
		list1 = list1->next;
		
	}

	while(list2){
		// cout<<list2->data<<" ";
		if(visited.find(list2)!=visited.end())
			return list2->data;
		list2 = list2->next;
	}
	return -1;
}

int main() {
	Node* newNode;
	Node* head1 = new Node(10);
	Node* head2 = new Node(3);
	
	head2->next = new Node(6);
    	head2->next->next = new Node(9); 

    	newNode = new Node(15); 
    	head1->next = newNode; 
    	head2->next->next->next = newNode; 

    	newNode = new Node(30);
    	head1->next->next = newNode; 
    	head2->next->next->next->next = newNode; 

    	cout<<"intersection point of lists uisng hash mehtod: "<<findIntersectionHash(head1,head2)<<endl;
	return 0;
}
