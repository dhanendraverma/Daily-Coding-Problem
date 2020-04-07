/*****************************************************************************************************************************
This problem was asked by Oracle.
Given a binary search tree, find the floor and ceiling of a given integer. The floor is the highest element in the tree less 
than or equal to an integer, while the ceiling is the lowest element in the tree greater than or equal to an integer.
If either value does not exist, return None.
******************************************************************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

class Node{
    public:
    int val;
    Node *left, *right;
    Node(int data){
        this->val = data;
        this->left = this->right = NULL;
    }
};

int getCeil(Node* node,int data){
    if(!node)
        return -1;
    if(node->val==data)
        return node->val;
    if(node->val < data)
        return getCeil(node->right,data);
    int Ceil = getCeil(node->left,data);
    return (Ceil>=data)?Ceil:node->val;
}

int getFloor(Node* node,int data){
    if(!node)
        return INT_MAX;
    if(node->val == data)
        return node->val;
    if(node->val > data)
        return getFloor(node->left,data);
    int Ceil = getFloor(node->right,data);
    return (Ceil<=data)?Ceil:node->val;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    cout<<getCeil(root,15)<<endl;
    cout<<getCeil(root,5)<<endl;
    cout<<getFloor(root,3)<<endl;
	return 0;
}
