/**************************************************************************************************************************************
This problem was asked by Google.
Given a binary tree of integers, find the maximum path sum between two nodes. The path must go through at least one node, and does not 
need to go through the root.
***************************************************************************************************************************************/
#include <iostream>
#include <climits>
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

int maxPathSum(Node* node, int& ans) 
{ 
	if (!node) 
		return 0; 
	int l = maxPathSum(node->left,ans); 
	int r = maxPathSum(node->right,ans); 
	int max_single = max(max(l, r) + node->data, node->data); 
	int max_top = max(max_single, l + r + node->data); 
	ans = max(ans, max_top); 
	return max_single; 
} 

int main() {
	Node* root = new Node(10); 
    root->left        = new Node(2); 
    root->right       = new Node(10); 
    root->left->left  = new Node(20); 
    root->left->right = new Node(1); 
    root->right->right = new Node(-25); 
    root->right->right->left   = new Node(3); 
    root->right->right->right  = new Node(4); 
    int ans=INT_MIN;
    maxPathSum(root,ans);
    cout<<ans;
	return 0;
}
