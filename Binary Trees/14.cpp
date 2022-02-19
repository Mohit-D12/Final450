// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

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
    int height(TreeNode* root, bool& is_balanced)
    {
        if(!root || !is_balanced)
            return 0;
        
        int left = height(root->left, is_balanced);
        
        if(!is_balanced)
            return 0;
        
        int right = height(root->right, is_balanced);
        is_balanced = is_balanced && (abs(left - right) <= 1);
        
        if(!is_balanced)
            return 0;
        
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        height(root, res);
        return res;
    }

};