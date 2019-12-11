/**************************************************************************************************************************************
This problem was asked by Google.
Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.
For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:
    5
   / \
  3   7
 / \   \
2   4   8
***************************************************************************************************************************************/

#include <bits/stdc++.h> 
using namespace std; 

class Node{
	public:
	int data;
	Node *left, *right;
	Node(int data) { 
	this->data = data; 
	this->left = this->right = NULL; 
	}
}; 

struct Node* BSTrecur(vector<int> postOrder, int& postIndex, int key, int min, int max) { 
	if(postIndex<0) 
		return NULL; 
	Node* root = NULL; 
	if (key>min && key<max){ 
		root = new Node(key); 
		postIndex = postIndex - 1; 
		if (postIndex>=0){ 
		root->right = BSTrecur(postOrder, postIndex,postOrder[postIndex],key, max); 
		root->left = BSTrecur(postOrder, postIndex,postOrder[postIndex],min, key); 
		} 
	} 
	return root; 
} 

Node* constructBST(vector<int> postOrder) { 
	int postIndex = postOrder.size()-1; 
	return BSTrecur(postOrder, postIndex,postOrder[postIndex],INT_MIN, INT_MAX); 
} 

void printInorder (Node* node){ 
	if (!node) 
		return; 
	printInorder(node->left); 
	cout<<node->data<<" "; 
	printInorder(node->right); 
} 

 
int main () { 
	vector<int> postOrder = {1, 7, 5, 50, 40, 10}; 
	Node* root = constructBST(postOrder); 
	printInorder(root); 
	return 0; 
} 
