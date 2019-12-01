/**************************************************************************************************************************************
This problem was asked by Google.
Determine whether a doubly linked list is a palindrome. What if it’s singly linked?
For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class SNode{
	public:
	char data;
	SNode* next;
	SNode(char data){
		this->data = data;
		next = NULL;
	}
};

class SLinkedList{
	public:
	SNode* head;
	SLinkedList(){
		head = NULL;
	}
	
	void push(char data){
		SNode* node = new SNode(data);
		node->next = head;
		head = node;
	}
	
	void reverse(SNode** head){
		SNode *prev = NULL,*curr = *head, *next=NULL;
		while(curr){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		*head = prev;
	}
	
	bool matchList(SNode* head1, SNode* head2){
		while(head1 && head2){
			if(head1->data!=head2->data)
				return false;
			head1 = head1->next;
			head2 = head2->next;
		}
		return true;
	}
	
	bool isPalindrome(){
		if(!head)
			return NULL;
		SNode *slow = head, *fast = head;
		SNode *prev_slow = NULL, *mid = NULL;
		while(fast && fast->next){
			fast = fast->next->next;
			prev_slow = slow;
			slow = slow->next;
		}
		if(fast){
			mid = slow;
			slow = slow->next;
		}
		prev_slow->next=NULL;
		reverse(&slow);
		bool ans = matchList(head,slow);
		reverse(&slow);
		if(mid){
			prev_slow->next = mid;
			mid->next = slow;
		}
		else
			prev_slow->next = slow;
		return ans;
	}
	
};

class Node{
	public:
	char data;
	Node* next;
	Node* prev;
	Node(char data){
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

class DLinkedList{
	public:
	Node* head;
	DLinkedList(){
		head = NULL;
	}
	void push(char data){
		Node* node = new Node(data);
		node->next = head;
		if(head!=NULL)
			head->prev = node;
		head = node;
	}
	
	bool isPalindrome(){
		if(!head)
			return NULL;
		Node *left = head, *right = head;
		while(right->next)
			right = right->next;
		while(left!=right){
			if(left->data!=right->data)
				return false;
			left = left->next;
			right = right->prev;
		}
		return true;
	}
	
};

int main() {
	DLinkedList ll;
	ll.push('1');
	ll.push('4');
	ll.push('3');
	ll.push('4');
	ll.push('1');
	cout<<ll.isPalindrome()<<endl;
	SLinkedList sll;
	sll.push('1');
	sll.push('4');
	sll.push('3');
	sll.push('4');
	sll.push('1');
	cout<<sll.isPalindrome()<<endl;
	return 0;
}
