// Count BST nodes that lie in a given range
// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

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
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


int getCount(Node *root, int l, int h)
{
  // your code goes here  
    if(!root)
        return 0;
    
    if(root->data < l)
        return getCount(root->right, l, h);
    
    if(root->data > h)
        return getCount(root->left, l, h);
    
    return 1 + getCount(root->right, l, h) + getCount(root->left, l, h);
    
}