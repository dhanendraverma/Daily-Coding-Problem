/******************************************************************************************************************************
This problem was asked by Google.
<br>Given a binary search tree and a range [a, b] (inclusive), return the sum of the elements of the binary search tree within 
the range.
<br>For example, given the following tree:

    5
   / \
  3   8
 / \ / \
2  4 6  10
and the range [4, 9], return 23 (5 + 4 + 6 + 8).
******************************************************************************************************************************/

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *right,*left;
    Node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

int treeSumInRange(Node* node,int a,int b){
    if(!node)
        return 0;
    if(node->val >= a && node->val <= b)
        return node->val + treeSumInRange(node->left,a,b) + treeSumInRange(node->right,a,b);
    else if(node->val < a)
        return treeSumInRange(node->right,a,b);
    return treeSumInRange(node->left,a,b);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->right = new Node(4);
    root->left->left = new Node(2);
    root->right->left = new Node(6);
    root->right->right = new Node(10);
    int a = 4, b = 9;
    cout<<treeSumInRange(root,a,b);
	return 0;
}
