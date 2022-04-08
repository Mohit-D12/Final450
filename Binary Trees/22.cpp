// check sum tree
// https://practice.geeksforgeeks.org/problems/sum-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
    pair<int, bool> solve(Node* root) {
        
        if(!root)
            return {0, true};
        
        if(!root->left && !root->right)
            return {root->data, true};
        
        pair<int, bool> left = solve(root->left);
        if(!left.second)
            return left;
        
        pair<int, bool> right = solve(root->right);
        if(!right.second)
            return right;
        
        return {2 * root->data, root->data == (left.first + right.first)};
    }
    
    public:
    bool isSumTree(Node* root)
    {
        // Your code here
        return solve(root).second;
    }
};