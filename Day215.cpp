/**************************************************************************************************************************************
This problem was asked by Yelp.
The horizontal distance of a binary tree node describes how far left or right the node will be when the tree is printed out.
More rigorously, we can define it as follows:
The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.
For example, for the following tree, hd(1) = -2, and hd(6) = 0.
             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8
The bottom view of a tree, then, consists of the lowest node at each horizontal distance. If there are two nodes at the same depth 
and horizontal distance, either is acceptable.
For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].
Given the root to a binary tree, return its bottom view.
***************************************************************************************************************************************/
#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node{
	public:
	int data;
	Node *left, *right;
	Node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};

void bottomViewRecur(Node* node, int curr, int dist, map<int,pair<int,int>>& mp){
	if(!node)
		return;
	if(mp.find(dist)==mp.end() || mp[dist].second<=curr)
		mp[dist] = {node->data,curr};
	bottomViewRecur(node->left,curr+1,dist-1,mp);
	bottomViewRecur(node->right,curr+1,dist+1,mp);
}

map<int,pair<int,int>> getBottomView1(Node* root){
	map<int,pair<int,int>> mp;
	bottomViewRecur(root,0,0,mp);
	return mp;
}

map<int,int> getBottomView(Node* root){
	if(!root)
		return {};
	queue<pair<Node*,int>> q;
	int dist=0;
	map<int,int> mp;
	q.push({root,0});
	while(!q.empty()){
		pair<Node*,int> temp = q.front();
		q.pop();
		mp[temp.second] = temp.first->data;
		if(temp.first->left)
			q.push({temp.first->left,temp.second-1});
		if(temp.first->right)
			q.push({temp.first->right,temp.second+1});
	}
	return mp;
}


int main() {
	Node* root = new Node(5);
	root->left = new Node(3);
	root->right = new Node(7);
	root->left->left = new Node(1);
	root->left->right = new Node(4);
	root->left->left->left = new Node(0);
	root->right->left = new Node(6);
	root->right->right = new Node(9);
	root->right->right->left = new Node(8);
	map<int,int> bottomView = getBottomView(root);
	for(auto i:bottomView)
		cout<<i.second<<" ";
	cout<<endl;
	map<int,pair<int,int>> btmView = getBottomView1(root);
	for(auto i:btmView)
		cout<<i.second.first<<" ";
	return 0;
}
