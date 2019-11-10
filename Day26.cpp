/**************************************************************************************************************************************
This problem was asked by Google.
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length 
of the list.
The list is very long, so making more than one pass is prohibitively expensive.
**************************************************************************************************************************************/
#include <iostream>
using namespace std;

class LinkedList{
	public:
		class node{
			public:
				int data;
				node* next;
				node(int d){
					data  = d;
					next = NULL;
				}
		};
		
		node* head;
		
		node* deleteNode(int nodenum){
			node *first = head;
			node *second = head;
			int i=0;
			while(i<nodenum){
				if(second->next==NULL){
					if(i==nodenum-1)
						head = head->next;
					return head;
				}
				second = second->next;
			}
			
			while(second->next!=NULL){
				first = first->next;
				second = second->next;
			}
			
			first->next = first->next->next;
			return head;
		}
		
		node* push(int new_data){
			node* new_node = new node(new_data);
			new_node->next = head;
			head = new_node;
			return head;
		}
		
		void printList(){ 
			node* tnode = head; 
			while (tnode != NULL){ 
				cout << (tnode->data) << ( " "); 
				tnode = tnode->next; 
				
			} 
			
		} 
};


int main() {
	LinkedList* llist = new LinkedList(); 
  
    llist->head = llist->push(7); 
    llist->head = llist->push(1); 
    llist->head = llist->push(3); 
    llist->head = llist->push(2); 
  
    cout<<"Given Linked list is: ";
    llist->printList(); 
  
    int N = 1; 
    llist->head = llist->deleteNode(N); 
  
    cout<<endl<<"Linked List after Deletion is: ";
    llist->printList();
	
	return 0;
}
