// validate BST
// https://leetcode.com/problems/validate-binary-search-tree/

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
    
    bool validate(TreeNode* root, long long up, long long down) {
        
        if(!root)
            return true;
        
        return (root->val > down && root->val < up) 
            && validate(root->left, root->val, down) 
            && validate(root->right, up, root->val);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        
        long long up = INT_MAX + 1ll;
        long long down = INT_MIN - 1ll;
        
        return validate(root, up, down);
    }
};