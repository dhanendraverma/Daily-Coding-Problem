/**************************************************************************************************************************************
This problem was asked by Apple.
Given the root of a binary tree, find the most frequent subtree sum. The subtree sum of a node is the sum of all values under a node,
including the node itself.
For example, given the following tree:
  5
 / \
2  -5
Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5.
**************************************************************************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class Node{
	public:
	int data;
	Node *left,*right;
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int findSum(Node* node,map<int,int>& mp){
	int sum = node->data;
	if(!node->left && !node->right)
		mp[sum]++;
	else{
		if(node->left)
			sum += findSum(node->left,mp);
		if(node->right)
			sum += findSum(node->right,mp);
	}
	mp[sum]++;
	return sum;
}

int mostFrequentSum(Node* root){
	map<int,int> count;
	findSum(root,count);
	int ans,f=0;
	for(auto i:count){
		if(i.second>f){
			ans = i.first;
			f = i.second;
		}
	}
	return ans;
}

int main() {
	Node* root = new Node(5);
	root->left = new Node(2);
	root->right = new Node(-5);
	cout<<mostFrequentSum(root);
	return 0;
}
