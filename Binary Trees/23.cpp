// Check if leafs are at same level
// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
    
    int level;
    
    void check_level(Node* root, int curr) {
        
        if(!root)
            return;
            
        if(level == -2)
            return;
        
        if(!root->left && !root->right) {
            
            if(level == -1)
                level = curr;
            else if(curr != level)
                level = -2;
        }
        
        check_level(root->left, curr + 1);
        check_level(root->right, curr + 1);
    }
    
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        level = -1;
        check_level(root, 0);
        
        return (level != -2);
    }
};