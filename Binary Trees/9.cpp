// Left View of Binary Tree 
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

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
 
 void dfs(Node* root, int level, vector<int>& result) {
     
     if(!root)
        return;
     
    if(level >= result.size())
        result.push_back(root->data);
        
    level++;
    
    dfs(root->left, level, result);
    dfs(root->right, level, result);
 }

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> result;
   dfs(root, 0, result);
   return result;
}