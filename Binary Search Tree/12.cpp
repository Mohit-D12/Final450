// Kth largest Element in BST
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    int c;
    int find_kth_largest(Node* root) {
        
        if(!root)
            return -1;
            
        int x = find_kth_largest(root->right);
        
        if(c == 0)
            return x;
        
        c--;
        if(c == 0)
            return root->data;
        
        return find_kth_largest(root->left);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        this->c = K;
        return find_kth_largest(root);
    }
};
