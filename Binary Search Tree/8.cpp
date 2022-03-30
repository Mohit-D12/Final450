// BST from Preorder
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    
    int index, size;
    
    TreeNode* construct_bst(vector<int>& preorder, int val) {
        
        if(index >= size || preorder[index] > val)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        
        root->left = construct_bst(preorder, preorder[index - 1]);
        root->right = construct_bst(preorder, val);
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        index = 0;
        size = preorder.size();
        
        return construct_bst(preorder, INT_MAX);
    }
};









