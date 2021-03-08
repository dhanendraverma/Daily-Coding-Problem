/**************************************************************************************************************************************
This problem was asked by Google.
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length 
of the list.
The list is very long, so making more than one pass is prohibitively expensive.
**************************************************************************************************************************************/#include <iostream>
using namespace std;

class LinkedList{
	public:
		class Node{
			public:
				int data;
				Node* next;
				Node(int d){
					this->data = d;
					this->next = NULL;
				}
		};
		
		Node* head;
		
		LinkedList(){
			this->head = NULL;
		}
		
		void insert(int d){
			Node* curr = new Node(d);
			if(!head)
				head=curr;
			else{
				curr->next = head;
				head = curr;
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
		
		void deleteKthFromLast(int k){
			Node *fast = this->head, *slow = this->head;
			while(k--)
				fast = fast->next;
			while(fast->next){
				fast = fast->next;
				slow = slow->next;
			}
			slow->next = slow->next->next;
		}
};


int main() {
	LinkedList ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	ll.insert(6);
	ll.insert(7);
	ll.insert(8);
	ll.insert(9);
	ll.printList();
	ll.deleteKthFromLast(3);
	ll.printList();
	return 0;
}
