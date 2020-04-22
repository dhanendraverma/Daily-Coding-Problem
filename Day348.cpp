/******************************************************************************************************************************
This problem was asked by Zillow.
A ternary search tree is a trie-like data structure where each node may have up to three children. Here is an example which 
represents the words code, cob, be, ax, war, and we.

       c
    /  |  \
   b   o   w
 / |   |   |
a  e   d   a
|    / |   | \ 
x   b  e   r  e  

The tree is structured according to the following rules:
left child nodes link to words lexicographically earlier than the parent prefix
right child nodes link to words lexicographically later than the parent prefix
middle child nodes continue the current word
For instance, since code is the first word inserted in the tree, and cob lexicographically precedes cod, cob is represented as
a left child extending from cod.
Implement insertion and search functions for a ternary search tree.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node *left, *center, *right;
    bool isEnd;
    Node(char data){
        this->data = data;
        this->left = this->right = this->center = NULL;
        this->isEnd = false;
    }
};

bool search(Node* node,string word,int i){
    if(!node)
        return false;
    if(word[i] < node->data)
        return search(node->left,word,i);
    else if(word[i] > node->data)
        return search(node->right,word,i);
    else{
        if(i==word.length()-1)
            return node->isEnd;
        return search(node->center,word,i+1);
    }
    
}

void insert(Node** node,string word,int i){
    if(!(*node))
        *node = new Node(word[i]);
    if(word[i] < (*node)->data)
        insert(&((*node)->left),word,i);
    else if(word[i] > (*node)->data)
        insert(&((*node)->right),word,i);
    else{
        if(i < word.length()-1)
            insert(&((*node)->center),word,i+1);
        else
            (*node)->isEnd = true;
    }
}

int main() {
    Node* root = NULL;
    insert(&root,"code",0);
    insert(&root,"cob",0);
    insert(&root,"be",0);
    insert(&root,"ax",0);
    insert(&root,"war",0);
    insert(&root,"we",0);
    cout<<search(root,"war",0)<<endl;
	return 0;
}
