/******************************************************************************************************************************
This problem was asked by Netflix.
A Cartesian tree with sequence S is a binary tree defined by the following two properties:
It is heap-ordered, so that each parent value is strictly less than that of its children.
An in-order traversal of the tree produces nodes with values that correspond exactly to S.
For example, given the sequence [3, 2, 6, 1, 9], the resulting Cartesian tree would be:

      1
    /   \   
  2       9
 / \
3   6
Given a sequence S, construct the corresponding Cartesian tree.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* buildTreeRec(int root,vector<int>& S,vector<int>& parent,vector<int>& left,vector<int>& right){
    if(root == -1)
        return NULL;
    Node* tmp = new Node(S[root]);
    tmp->left = buildTreeRec(left[root],S,parent,left,right);
    tmp->right = buildTreeRec(right[root],S,parent,left,right);
    return tmp;
}

Node* cartesianTree(vector<int>& S){
    int n = S.size();
    vector<int> parent(n,-1), left(n,-1), right(n,-1);
    int root = 0, last;
    for(int i=1;i<n;i++){
        last = i-1;
        right[i] = -1;
        while(S[last]>=S[i] && last!=root)
            last = parent[last];
        if(S[last]>=S[i]){
            parent[root] = i;
            left[i] = root;
            root = i;
        }
        else if(right[last]==-1){
            right[last] = i;
            parent[i] = last;
            left[i] = -1;
        }
        else{
            parent[right[last]] = i;
            left[i] = right[last];
            right[last] = i;
            parent[i] = last;
        }
    }
    parent[root] = -1;
    return buildTreeRec(root,S,parent,left,right);
}

void inorder(Node* node){
    if(!node)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}


int main() {
    vector<int> S = {3, 2, 6, 1, 9};
    Node* root = cartesianTree(S);
    inorder(root);
	return 0;
}
