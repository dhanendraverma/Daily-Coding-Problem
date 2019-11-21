/****************************************************************************************************************************************
This problem was asked by Google.
Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.
For example, given the following preorder traversal:
[a, b, d, e, c, f, g]
And the following inorder traversal:
[d, b, e, a, f, c, g]
You should return the following tree:
    a
   / \
  b   c
 / \ / \
d  e f  g
*****************************************************************************************************************************************/
#include <bits/stdc++.h> 
using namespace std; 

class Node 
{ 
	public: 
	char data; 
	Node* left; 
	Node* right; 
}; 

Node* newNode(char data) 
{ 
	Node* node = new Node(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return node; 
} 

int search(vector<char> arr, int strt, int end, char value) 
{ 
	for (int i = strt; i <= end; i++) 
		if (arr[i] == value) 
			return i; 
	
}

Node* buildTree(vector<char> inorder, vector<char> preorder, int inStrt, int inEnd) 
{ 
	static int preIndex = 0; 

	if (inStrt > inEnd) 
		return NULL; 
	Node* curr_node = newNode(preorder[preIndex++]); 
	if (inStrt == inEnd) 
		return curr_node; 
	int inIndex = search(inorder, inStrt, inEnd, curr_node->data); 
	curr_node->left = buildTree(inorder, preorder, inStrt, inIndex - 1); 
	curr_node->right = buildTree(inorder, preorder, inIndex + 1, inEnd); 
	return curr_node; 
} 

void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	cout<<node->data<<" "; 
	printInorder(node->right); 
} 


int main() 
{ 
	vector<char> inorder = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
	vector<char> preorder = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
	Node* root = buildTree(inorder, preorder, 0, inorder.size()-1); 
	printInorder(root); 
} 
