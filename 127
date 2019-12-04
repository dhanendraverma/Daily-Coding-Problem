/*************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Microsoft.
Let's represent an integer in a linked list format by having each node represent a digit in the number. The nodes make up the number
in reversed order.
For example, the following linked list:
1 -> 2 -> 3 -> 4 -> 5
is the number 54321.
Given two linked lists in this format, return their sum in the same linked list format.
For example, given
9 -> 9
5 -> 2
return 124 (99 + 25) as:
4 -> 2 -> 1
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
	
	void findSum(Node* a, Node* b){
		LinkedList ansList;
		if(!a)
			ansList.head = b;
		else if(!b)
			ansList.head = a;
		else{
			int s,carry=0;
			Node *prev=NULL, *temp;
			while(a || b){
				s = carry+(a?a->data:0)+(b?b->data:0);
				carry = (s>=10)?1:0;
				s = s%10;
				temp = new Node(s);
				if(!prev)
					ansList.head = temp;
				else
					prev->next = temp;
				prev = temp;
				if(a) a = a->next;
				if(b) b = b->next;
			}
			if(carry){
				temp->next = new Node(carry);
			}
		ansList.printList();
		}
	}
};

int main() {
	LinkedList ll1, ll2;
	ll1.insert(9);
	ll1.insert(9);
	ll1.insert(1);
	ll1.printList();
	ll2.insert(2);
	ll2.insert(5);
	ll2.insert(9);
	ll2.printList();
	ll1.findSum(ll1.head, ll2.head);
	return 0;
}
