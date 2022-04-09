// sum-of-the-longest-bloodline-of-a-tree
// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    int max_sum, max_level;
    
    void solve(Node* root, int level, int sm) {
        
        if(!root)
            return;
            
        sm += root->data;
        
        if(!root->left && !root->right) {
            
            if(level > max_level) {
                
                max_level = level;
                max_sum = sm;
            }
            
            else if(level == max_level && max_sum < sm) {
                
                max_level = level;
                max_sum = sm;
            }
            
            return;
        }
        
        solve(root->left, level + 1, sm);
        solve(root->right, level + 1, sm);
    }
    
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        max_sum = INT_MIN;
        max_level = -1;
        
        int sum = 0;
        
        solve(root, 0, sum);
        
        return max_sum;
    }
};

