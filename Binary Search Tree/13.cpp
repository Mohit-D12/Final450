// kth smallest element in bst
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

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

class Solution {
    int c;
    int find_kth_largest(Node* root) {
        
        if(!root)
            return -1;
            
        int x = find_kth_largest(root->left);
        
        if(c == 0)
            return x;
        
        c--;
        if(c == 0)
            return root->data;
        
        return find_kth_largest(root->right);
    }
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        this->c = K;
        return find_kth_largest(root);
    }
};