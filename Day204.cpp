/**************************************************************************************************************************************
This problem was asked by Amazon.
Given a complete binary tree, count the number of nodes in faster than O(n) time. Recall that a complete binary tree has every level 
filled except the last, and the nodes in the last level are filled starting from the left.
***************************************************************************************************************************************/

#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *left, *right;
	Node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};

int leftHeight(Node* node){
	int h=0;
	while(node){
		h++;
		node = node->left;
	}
	return h;
}

int rightHeight(Node* node){
	int h=0;
	while(node){
		h++;
		node = node->right;
	}
	return h;
}

int countNodes(Node* root){
	if(!root)
		return 0;
	int lh = leftHeight(root);
	int rh = rightHeight(root);
	if(lh==rh)
		return (1<<lh)-1;
	return countNodes(root->left)+countNodes(root->right)+1;
}


int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->left = new Node(10);
	cout<<countNodes(root)<<endl;
	return 0;
}
