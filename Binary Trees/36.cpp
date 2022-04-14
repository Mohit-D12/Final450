// Burning Tree
// https://practice.geeksforgeeks.org/problems/burning-tree/1#

#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node* left;
    Node* right;
};

class Solution {
    
    // pair { height, depth of target (-1) }
    pair<int, int> solve(Node* root, int target, int& time_taken) {
        
        if(!root)
            return {0, -1};
        
        pair<int, int> left = solve(root->left, target, time_taken);
        pair<int, int> right = solve(root->right, target, time_taken);
        
        
        if(root->data == target) {
            
            time_taken = max(left.first, right.first);
            return { time_taken + 1, 1};
        }
        
        if(left.second == -1 && right.second == -1) {
            
            return { max(left.first, right.first) + 1, -1};
        }
        
        if(left.second != -1) {
            
            time_taken = max(time_taken, left.second + right.first);
            return {max(left.first, right.first) + 1, left.second + 1};
        }
        if(right.second != -1) {
            
            time_taken = max(time_taken, right.second + left.first);
            return {max(right.first, right.first) + 1, right.second + 1};
        }
        
        
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        int time_taken = 0;
        solve(root, target, time_taken);
        
        return time_taken;
    }
};