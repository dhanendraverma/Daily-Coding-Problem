/**************************************************************************************************************************************
This question was asked by BufferBox.
Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed.
For example, given the following tree:
   0
  / \
 1   0
    / \
   1   0
  / \
 0   0
should be pruned to:
   0
  / \
 1   0
    /
   1
We do not remove the tree at the root or its left child because it still has a 1 as a descendant.
***************************************************************************************************************************************/

#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void printInorder(Node* node){
	if(!node)
		return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

Node* pruneTree(Node* root){
	if(!root)
		return NULL;
	root->left = pruneTree(root->left);
	root->right = pruneTree(root->right);
	if(root->data==0 && !root->left && !root->right)
		return NULL;
	return root;
}

int main() {
	Node* root = new Node(0);
	root->left = new Node(1);
	root->right = new Node(0);
	root->right->left = new Node(1);
	root->right->right = new Node(0);
	root->right->left->right = new Node(0);
	root->right->left->left = new Node(0);
	printInorder(root);
	cout<<endl;
	Node* newRoot = pruneTree(root);
	printInorder(newRoot);
	return 0;
}
