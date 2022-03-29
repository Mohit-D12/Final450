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
        
        if(root->val == key) {
            
            //case 1: no child
            if(!root->left && !root->right)
                return NULL;
            
            //case 2: 1 child
            else if(!root->left)
                return  root->right;
            
            else if(!root->right)
                return root->left;
            
            //case 3: 2 children 
            else {
                
                TreeNode* minNode = root -> right;
                while (minNode -> left != NULL)
                    minNode = minNode -> left;
                
                minNode -> left = root -> left;
                return root -> right;
                
            }
        }
        else {
            
            if(root->val > key)
                root->left = deleteNode(root->left, key);
            else
                root->right = deleteNode(root->right, key);
        }
        
        return root;
    }
};