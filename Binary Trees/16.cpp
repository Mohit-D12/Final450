// Boundary Traversal of binary tree
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
    
  public:
    vector <int> boundary(Node *root) {

        //Your code here
        if(!root)
            return {};
        
        vector<int> boundary(1, root->data);
        
        fill_left(root->left, boundary);
        if(root->left || root->right)
            fill_leaves(root, boundary);
        fill_right_reverse(root->right, boundary);
        
        return boundary;
    }

    void fill_left(Node* root, vector<int>& v) {
        
        if(!root)
            return;
            
        if(root->left || root->right)
            v.push_back(root->data);
        else
            return;
        
        if(root->left)
            fill_left(root->left, v);
        else if(root->right)
            fill_left(root->right, v);
    }
    void fill_leaves(Node*root, vector<int>& v) {

        if(!root)
            return;
            
        if(root->left || root->right)
        {
            fill_leaves(root->left, v);
            fill_leaves(root->right, v);
        }
        else
            v.push_back(root->data);
    }
    
    void fill_right_reverse(Node*root, vector<int>& v) {
        
        if(!root)
            return;
            
        if(root->right)
            fill_right_reverse(root->right, v);
            
        else if(root->left)
            fill_right_reverse(root->left, v);
            
        if(root->left || root->right)
            v.push_back(root->data);
    }

};