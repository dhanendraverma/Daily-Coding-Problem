/**************************************************************************************************************************************
This problem was asked by Microsoft.
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.
Given the root to such a tree, write a function to evaluate it.
For example, given the following tree:
    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	string data;
	Node* left;
	Node* right;
	Node(string s){
		data = s;
	}
 };
 
 
 int evaluate(Node* root){
 	if(!root)
 		return 0;
 	if(!root->left && !root->right)
 		return stoi(root->data);
 	int left = evaluate(root->left);
 	int right = evaluate(root->right);
 	if(root->data=="+")
 		return left+right;
 	if(root->data=="-")
 		return left-right;
 	if(root->data=="*")
 		return left*right;
 	return left/right;
 }

int main() {
	Node* root = new Node("*"); 
	root->left = new Node("+"); 
	root->left->left = new Node("3"); 
	root->left->right = new Node("2"); 
	root->right = new Node("+"); 
	root->right->left = new Node("4"); 
	root->right->right = new Node("5"); 
	cout << evaluate(root);
	return 0;
}
