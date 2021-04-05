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

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Node{
	public:
		int val;
		Node *left, *right;
		Node(int val){
			this->val = val;
			this->left = this->right = NULL;
		}
};

Node* constructTreeItr(vector<int> postorder){
	stack<Node*> st;
	int n = postorder.size()-1;
	Node* root = new Node(postorder[n]);
	st.push(root);
	Node* temp;
	n--;
	while(n>=0){
		temp = NULL;
		while( !st.empty() && st.top()->val > postorder[n]){
			temp = st.top();
			st.pop();
		}
		if(temp){
			temp->left = new Node(postorder[n]);
			st.push(temp->left);
		}
		else{
			// cout<<'t'<<endl;
			st.top()->right = new Node(postorder[n]);
			st.push(st.top()->right);
		}
		n--;
	}
	return root;
}

Node* constructTreeRec(vector<int>& postorder, int& postIndex, int key, int min, int max){
	if(postIndex<0)
		return NULL;
	Node* root = NULL;
	if(key > min && key < max){
		root = new Node(key);
		postIndex--;
		if(postIndex >= 0)
			root->right = constructTreeRec(postorder, postIndex, postorder[postIndex], key, max);
		if(postIndex >= 0)
			root->left = constructTreeRec(postorder, postIndex, postorder[postIndex], min, key);
	}
	return root;
}


Node* constructTree(vector<int> postorder){
	int postIndex = postorder.size()-1;
	return constructTreeRec(postorder, postIndex, postorder[postIndex], INT_MIN, INT_MAX);
}

void printInorder (Node* node){ 
	if (!node) 
		return; 
	printInorder(node->left); 
	cout<<node->val<<" "; 
	printInorder(node->right); 
} 

int main() {
	vector<int> postorder = {1, 7, 5, 50, 40, 10};
	Node* root = constructTree(postorder);
	printInorder(root);
	root = constructTreeItr(postorder);
	printInorder(root);
	return 0;
}
