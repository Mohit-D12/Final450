// Maximum sum of Non-adjacent nodes 
// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
    
    // pair {inc, exc}
    pair<int, int> solve(Node* root) {
        
        if(!root)
            return {0, 0};
            
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> result = {0, 0};
        
        result.first = root->data + left.second + right.second;
        result.second = max(left.first, left.second) + max(right.first, right.second);
    
        return result;
    }
    
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> result = solve(root);
        
        return max(result.first, result.second);
    }
};