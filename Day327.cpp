/******************************************************************************************************************************
This problem was asked by Salesforce.
Write a program to merge two binary trees. Each node in the new tree should hold a value equal to the sum of the values of 
the corresponding nodes of the input trees.
If only one input tree has a node in a given position, the corresponding node in the new tree should match that input node.
******************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *left,*right;
    Node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

void inorder(Node* node){
    if(!node)
        return;
    inorder(node->left);
    cout<<node->val<<" ";
    inorder(node->right);
}

Node* mergeBinaryTree(Node* node1,Node* node2){
    if(!node1 && !node2)
        return NULL;
    if(!node2)
        return node1;
    else if(!node1)
        return node2;
    Node* tmp = new Node(node1->val+node2->val);
    tmp->left = mergeBinaryTree(node1->left,node2->left);
    tmp->right = mergeBinaryTree(node1->right,node2->right);
    return tmp;
}

int main() {
    Node *root1 = new Node(1); 
    root1->left = new Node(2); 
    root1->right = new Node(3); 
    root1->left->left = new Node(4); 
    root1->left->right = new Node(5); 
    root1->right->right = new Node(6); 
    
    Node *root2 = new Node(4); 
    root2->left = new Node(1); 
    root2->right = new Node(7); 
    root2->left->left = new Node(3); 
    root2->right->left = new Node(2); 
    root2->right->right = new Node(6);
    Node* root = mergeBinaryTree(root1,root2);
    inorder(root);
	return 0;
}
