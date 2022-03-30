// Populate successor pointer
// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution
{
    Node* suc;
    void populate(Node* root) {
        
        if(!root)
            return;
            
        populate(root->right);
        root->next = suc;
        suc = root;
        
        populate(root->left);
    }
    
public:
    void populateNext(Node *root)
    {
        //code here
        suc = NULL;
        populate(root);
    }
};