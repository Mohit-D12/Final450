// Binary Tree to BST
// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

class Solution{
    vector<int> inorder;
    int index;
    
    void populate_vector(Node* root) {
        
        if(!root)   return;
        
        inorder.push_back(root->data);
        populate_vector(root->left);
        populate_vector(root->right);
    }
    
    void populate_tree(Node* root) {
        
        if(!root)   return;
        
        populate_tree(root->left);
        root->data = inorder[index++];
        populate_tree(root->right);
    }
    
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        inorder.clear();
        index = 0;
        
        populate_vector(root);
        sort(inorder.begin(), inorder.end());
        populate_tree(root);
        return root;
    }
};