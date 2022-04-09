// Binary tree from inorder and preorder
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
    
    Node(int data) {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
    
    int root_index;
    unordered_map<int, int> MAP;
    
    Node* build(int* preorder, int start, int end) {
        
        if(start > end)
            return NULL;
        
        int root_val = preorder[root_index++];
        Node* root = new Node(root_val);
        
        root->left = build(preorder, start, MAP[root_val] - 1);
        root->right = build(preorder, MAP[root_val] + 1, end);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        root_index = 0;
        
        for(int i = 0; i < n; i++)
            MAP[in[i]] = i;
        
        return build(pre, 0, n - 1);
    }
};