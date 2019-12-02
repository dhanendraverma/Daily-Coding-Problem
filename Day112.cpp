/**************************************************************************************************************************************
This problem was asked by Twitter.
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. Assume that each node in the tree also has
a pointer to its parent.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node 
in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
***************************************************************************************************************************************/

#include <bits/stdc++.h> 
using namespace std; 

class Node 
{ 
	public:
	Node *left, *right, *parent; 
	int key;
	Node(int data){
		this->key = data;
		this->left = NULL;
		this->right = NULL;
		this->left = NULL;
	}
}; 

Node *insert(Node *node, int key) 
{ 
	if (!node) 
		return new Node(key); 
	if (key<node->key) 
	{ 
		node->left = insert(node->left, key); 
		node->left->parent = node; 
	} 
	else if (key>node->key) 
	{ 
		node->right = insert(node->right, key); 
		node->right->parent = node; 
	} 
	return node; 
} 

Node* findLCA(Node *n1, Node *n2) 
{ 
	map <Node *, bool> ancestors; 
	while (n1)
	{ 
		ancestors[n1] = true; 
		n1 = n1->parent; 
		
	} 
	while (n2) 
	{
	if (ancestors.find(n2) != ancestors.end()) 
		return n2; 
	n2 = n2->parent; 
} 
return NULL; 
} 
 
int main(void) 
{ 
	Node * root = NULL; 
	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 22); 
	root = insert(root, 4); 
	root = insert(root, 12); 
	root = insert(root, 10); 
	root = insert(root, 14); 
	Node *n1 = root->left->right->left; 
	Node *n2 = root->left; 
	Node *lca = findLCA(n1, n2); 
	cout<<lca->key; 
	return 0; 
} 
