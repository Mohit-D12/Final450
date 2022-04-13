// Deletion in BST
// https://leetcode.com/problems/delete-node-in-a-bst/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return NULL;
        
        if(root->val > key) {
            
            root->left = deleteNode(root->left, key);
            return root;
        }
        
        if(root->val < key) {
            
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        // root == val
        if(!root->left)
            return root->right;
        
        if(!root->right)
            return root->left;
        
        TreeNode* pred_parent = root;
        TreeNode* pred = root->right;
        
        while(pred->left) {
            
            pred_parent = pred;
            pred = pred->left;
        }
        
        if(pred_parent == root)
            pred_parent->right = pred->right;
        else
            pred_parent->left = pred->right;
        
        root->val = pred->val;
        return root;
    }
};