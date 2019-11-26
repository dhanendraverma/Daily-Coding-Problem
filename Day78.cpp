/**************************************************************************************************************************************
This problem was asked by Google.
Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
**************************************************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std; 

class Node 
{ 
	public:
	int data; 
	Node* next; 
	Node(int data){
		this->data = data;
		next = NULL;
	}
}; 


void printList(Node* node) 
{ 
	while (node) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
	} 
} 


Node* mergeSorted(Node* head1, Node* head2) 
{ 
	Node* merged = NULL; 
	if (!head1) 
		return head2; 
	else if(!head2) 
		return head1; 
	if(head1->data<=head2->data) 
	{ 
		merged = head1; 
		merged->next = mergeSorted(head1->next, head2); 
	} 
	else
	{ 
		merged = head2; 
		merged->next = mergeSorted(head1, head2->next); 
	} 
	return merged; 
} 
 
Node* sortKlists(vector<Node*> headList) 
{ 
	int k = headList.size()-1;
	while (k != 0) 
	{ 
		int i = 0, j = k; 
		while (i < j) 
		{ 
			headList[i] = mergeSorted(headList[i], headList[j]); 
			i++, j--; 
			if (i >= j) 
				k = j; 
		} 
	} 

	return headList[0]; 
} 

int main() 
{ 
	int k = 3;  
	vector<Node*> headList(k); 
	headList[0] = new Node(1); 
	headList[0]->next = new Node(3); 
	headList[0]->next->next = new Node(5); 
	headList[0]->next->next->next = new Node(7); 
	
	headList[1] = new Node(2); 
	headList[1]->next = new Node(4); 
	headList[1]->next->next = new Node(6); 
	headList[1]->next->next->next = new Node(8); 
	
	headList[2] = new Node(0); 
	headList[2]->next = new Node(9); 
	headList[2]->next->next = new Node(10); 
	headList[2]->next->next->next = new Node(11); 
	Node* head = sortKlists(headList); 

	printList(head); 

	return 0; 
} 
