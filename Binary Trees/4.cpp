// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

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
    
    int set_diameter(TreeNode* root, int& diameter) {
        
        if(root == NULL)
            return 0;
        
        int left = set_diameter(root->left, diameter);
        int right = set_diameter(root->right, diameter);
        
        diameter = max(diameter, left + right);
        
        return 1 + max(left, right);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        set_diameter(root, diameter);
        return diameter;
    }
};