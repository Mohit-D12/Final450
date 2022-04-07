// Right View of Binary Tree 
// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 
class Solution
{
    
    void dfs(Node* root, int level, vector<int>& result) {
     
         if(!root)
            return;
         
        if(level >= result.size())
            result.push_back(root->data);
            
        level++;
        
        dfs(root->right, level, result);
        dfs(root->left, level, result);
     }

    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> result;
       dfs(root, 0, result);
       return result;
    }
};