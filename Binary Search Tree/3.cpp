// Minimum element in BST
// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1#

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


int minValue(Node* root) {
    // Code here'
    
    if(!root)
        return -1;
        
    while(root->left)
        root = root->left;
        
    return root->data;
}