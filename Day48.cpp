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

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
	public:
		char val;
		Node *left, *right;
		Node(char val){
			this->val = val;
			this->left = this->right = NULL;
		}
};

unordered_map<char, int> mp;

void printTree(struct Node* node){
    if (!node)
        return;
    printTree(node->left);
    cout<<node->val<<" ";
    printTree(node->right);
}


Node* constructTreeRec(vector<char>& pre, vector<char>& In, int start, int end, int& curr_pre){
	if(start > end)
		return NULL;
	char curr = pre[curr_pre++];
    Node* node = new Node(curr);
	if(start == end)
		return node;
	int curr_in = mp[curr];
	node->left = constructTreeRec(pre, In, start, curr_in-1, curr_pre);
	node->right = constructTreeRec(pre, In, curr_in+1, end, curr_pre);
	return node;
}


Node* constructTree(vector<char> pre, vector<char> In){
	for(int i=0;i<In.size();i++)
		mp[In[i]] = i;
	int curr_in = 0;
	return constructTreeRec(pre,In,0,pre.size()-1,curr_in);
}


int main() {
	vector<char> preOrder = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
	vector<char> inOrder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};
	Node* root = constructTree(preOrder,inOrder);
	printTree(root);
	return 0;
}
