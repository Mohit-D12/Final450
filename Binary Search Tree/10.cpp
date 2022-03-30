// Balance a BST
// https://leetcode.com/problems/balance-a-binary-search-tree/

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
    
    vector<int> inorder;
    
    void populate_vector(TreeNode* root) {
        
        if(!root)   return;
        
        populate_vector(root->left);
        inorder.push_back(root->val);
        populate_vector(root->right);
    }
    
    TreeNode* populate_tree(int s, int e) {
        
        if(s > e)
            return NULL;
        
        int mid = s + (e - s)/2;
        
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = populate_tree(s, mid - 1);
        root->right = populate_tree(mid + 1, e);
        return root;
    }
    
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        inorder.clear();
        
        populate_vector(root);
        return populate_tree(0, inorder.size() - 1);
    }
};

// Approach 2
class Solution_Constant_Memory {
    int makeVineWithRR(TreeNode* grand) {
        auto curRoot = grand->right;
        int count = 0;
        
        while (curRoot) {
            if (curRoot->left) {
                auto oldRoot = curRoot;
                curRoot = curRoot->left;
                oldRoot->left = curRoot->right;
                curRoot->right = oldRoot;
                
                grand->right = curRoot; //move to the next new root
            } else {
                ++count;
                grand = curRoot;
                curRoot = curRoot->right;
            }
        }
        
        return count;
    }
    void compressVineWithLR(TreeNode* grand, int m) {
        auto curRoot = grand->right;
        
        while (m-- > 0) {
            auto oldRoot = curRoot;
            curRoot = curRoot->right;
            
            grand->right = curRoot;
            
            oldRoot->right = curRoot->left;
            curRoot->left = oldRoot;
            
            grand = curRoot;
            curRoot= curRoot->right;
        }
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode grand;
        grand.right = root;
        
        int countRR = makeVineWithRR(&grand);
        int balancedTreeHeight = log2(countRR + 1);
        int totalNodes = pow(2, balancedTreeHeight) - 1;
        
        compressVineWithLR(&grand, countRR - totalNodes);
        
        for (totalNodes = totalNodes / 2; totalNodes > 0; totalNodes /= 2) {
            compressVineWithLR(&grand, totalNodes);
        }    
        
        return grand.right;
    }
};