#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


void inorder(Node* root, Node*& pred) {
	
	if(root->left)
		inorder(root->left, pred);
	
	pred->right = root;
	pred = root;
	root->left = NULL;
	
	if(root->right)
		inorder(root->right, pred);
}

Node* flatten(Node* root)
{
	if(!root)
		return NULL;
	
    Node* dummy = new Node(-1);
	Node* pred = dummy;
	inorder(root, pred);
	
	return dummy->right;
}