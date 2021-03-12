/**************************************************************************************************************************************************************
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.
The list is very long, so making more than one pass is prohibitively expensive.
Do this in constant space and in one pass.
**************************************************************************************************************************************************************/

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
		
		void insert(int data){
			if(!head)
				head = new Node(data);
			else{
				Node* curr = new Node(data);
				curr->next = head;
				head = curr;
			}
		}
		
		void printList(){
			Node* curr = head;
			while(curr){
				cout<<curr->data<<" ";
				curr = curr->next;
			}
			cout<<endl;
		}
		
		void deleteKthFromLast(int k){
			Node *slow = head, *fast = head;
			while(k--)
				fast = fast->next;
			while(fast->next){
				fast = fast->next;
				slow = slow->next;
			}
			Node* KthLast = slow->next;
			slow->next = slow->next->next;
			free(KthLast);
		}
};

using namespace std;

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
