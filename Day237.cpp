/****************************************************************************************************************************
This problem was asked by Amazon.

A tree is symmetric if its data and shape remain unchanged when it is reflected about the root node. The following tree is 
an example:

        4
      / | \
    3   5   3
  /           \
9              9
Given a k-ary tree, determine whether it is symmetric.
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
		int data;
		vector<Node*> children;
		Node(int data){
			this->data = data;
		}
};

bool isSymmetricTree(Node* root1,Node* root2){
	if(!root1 && !root2)
		return true;
	else if(root1->data!=root2->data)
		return false;
	for(int i=0,j=root2->children.size()-1;i<root1->children.size(),j>=0;i++,j--){
		if(!isSymmetricTree(root1->children[i],root2->children[j]))
			return false;
	}
	return true;
}

int main() {
	Node* root = new Node(4);
	root->children.push_back(new Node(3));
	root->children.push_back(new Node(5));
	root->children.push_back(new Node(3));
	root->children[0]->children.push_back(new Node(9));
	root->children[2]->children.push_back(new Node(9));
	cout<<isSymmetricTree(root,root);
	return 0;
}
