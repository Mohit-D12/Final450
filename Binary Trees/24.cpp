// Duplicate subtree in Binary Tree
// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};

class Solution {
    
    unordered_set<string> sub_trees;
    bool is_dup;
    
    string check_dup(Node* root) {
        
        if(is_dup)
            return "";
        
        if(!root)
            return "N";
        
        string left = check_dup(root->left);
        
        if(is_dup)
            return "";
            
        string right = check_dup(root->right);
        
        if(is_dup)
            return "";
            
        string hash_code = left + root->data + right;
        
        if(hash_code.length() > 3) {
            
            if(sub_trees.count(hash_code))
                is_dup = true;
            else
                sub_trees.insert(hash_code);
        }
        
        return hash_code;
    }
    
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    int dupSub(Node *root) {
        
        // code here
        is_dup = false;
        sub_trees.clear();
        
        check_dup(root);
        
        return is_dup;
    }
};