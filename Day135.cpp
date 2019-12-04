/**************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This question was asked by Apple.
Given a binary tree, find a minimum path sum from root to a leaf.
For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.
  10
 /  \
5    5
 \     \
   2    1
       /
     -1
**************************************************************************************************************************************/
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
		this->right = NULL;
		this->left = NULL;
	}
};

void minPathSumUtil(Node* node,int curr_sum, int& ans){
	curr_sum += node->data;
	if(!node->left && !node->right)
		ans = min(ans,curr_sum);
	if(node->left)
		minPathSumUtil(node->left, curr_sum, ans);
	if(node->right)
		minPathSumUtil(node->right, curr_sum, ans);
}

int minPathSum(Node* root){
	int ans = INT_MAX;
	minPathSumUtil(root,0,ans);
	return ans;
}

int main() {
	Node* root = new Node(12);
	root->left = new Node(1);
	root->right = new Node(3);
	root->left->left = new Node(-25);
	root->left->right = new Node(-8);
	root->right->left = new Node(-3);
	root->right->right = new Node(2);
	cout<<minPathSum(root);
	return 0;
}
