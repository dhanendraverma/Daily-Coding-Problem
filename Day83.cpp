/*************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Google.
Invert a binary tree.
For example, given the following tree:
    a
   / \
  b   c
 / \  /
d   e f
should become:
  a
 / \
 c  b
 \  / \
  f e  d
**************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	char data;
	Node* left;
	Node* right;
	Node(char data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class BinaryTree{
	public:
	Node* head;
	BinaryTree(){
		head = NULL;
	}
	
	void printInorder(Node* node){
		if(!node)
			return; 
		cout<<node->data<<" ";
		printInorder(node->left);
		printInorder(node->right);
	}
	
	Node* swapNodes(Node* node){
		if(!node)
			return NULL;
		Node* leftNode = node->left;
		node->left = swapNodes(node->right);
		node->right = swapNodes(leftNode);
		return node;
	}
};

int main() {
	BinaryTree btree;
	btree.head = new Node('A');
	btree.head->left = new Node('B');
	btree.head->right = new Node('C');
	btree.head->left->right = new Node('E');
	btree.head->left->left = new Node('D');
	btree.head->right->left = new Node('F');
	btree.printInorder(btree.head);
	btree.swapNodes(btree.head);
  cout<<"Node after swapping left and right child ";
	btree.printInorder(btree.head);
	return 0;
}
