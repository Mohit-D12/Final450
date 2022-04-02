// Binary Tree to DLL
// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

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
    Node* flatten(Node* root, Node* next) {
        
        if(!root) {
            return root;
        }
        
        Node* head = root;
        if(root->left)
            head = flatten(root->left, root);
            
        if(root->right)
            root->right = flatten(root->right, next);
        else
            root->right = next;
            
        if(root->right)
            root->right->left = root;
        
        return head;
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        return flatten(root, NULL);
        
    }
};