/*****************************************************************************************************************************
This problem was asked by Yext.
Two nodes in a binary tree can be called cousins if they are on the same level of the tree but have different parents. 
For example, in the following diagram 4 and 6 are cousins.
    1
   / \
  2   3
 / \   \
4   5   6
Given a binary tree and a particular node, find all cousins of that node.
*****************************************************************************************************************************/

#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node *left,*right;
    Node(char data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

int getLevel(Node* root,Node* pnode,int level){
    if(!root)
        return 0;
    if(root==pnode)
        return level;
    int leftLevel = getLevel(root->left,pnode,level+1);
    return leftLevel?leftLevel:getLevel(root->right,pnode,level+1);
}

void getCousins(Node* root,Node* pnode,int level){
    if(!root || level<1)
        return;
    if(level==1){
        if(root->left==pnode || root->right==pnode)
            return;
        if(root->left)
            cout<<root->left->data<<" ";
        if(root->right)
            cout<<root->right->data<<" ";
    }
    getCousins(root->left,pnode,level-1);
    getCousins(root->right,pnode,level-1);
}

void findCousins(Node* root,Node* pnode){
    int plevel = getLevel(root,pnode,0);
    cout<<plevel<<endl;
    getCousins(root,pnode,plevel);
}


int main() {
    Node* root = new Node('1');
    root->left = new Node('2');
    root->right = new Node('3');
    root->left->left = new Node('4');
    Node* pnode = root->left->right = new Node('5');
    root->right->left = new Node('6');
    root->right->right = new Node('7');
    findCousins(root,pnode);
	return 0;
}
