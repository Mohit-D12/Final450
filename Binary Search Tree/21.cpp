// Largest BST
// https://practice.geeksforgeeks.org/problems/largest-bst/1#

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

struct info {
    
    int mx, mn, count;
    bool isValid;
    
    info(int mx, int mn, int count, bool isValid) {
        
        this->mx = mx;
        this->mn = mn;
        this->count = count;
        this->isValid = isValid;
    }
    info() {
        
        this->mx = INT_MIN;
        this->mn = INT_MAX;
        this->count = 0;
        this->isValid = true;
    }
    info(bool isValid) {
        
        this->mx = INT_MIN;
        this->mn = INT_MAX;
        this->count = 0;
        this->isValid = isValid;
    }
};

class Solution {
    
    int max_count;
    
    info get_largest_bst(Node* root) {
        
        if(!root)   return info();
        
        info left = get_largest_bst(root->left);
        info right = get_largest_bst(root->right);
        
        if(!left.isValid || !right.isValid)
            return info(false);
            
        if(root->data > left.mx && root->data < right.mn) {
            
            max_count = max(max_count, 1 + left.count + right.count);
            return info(max(left.mx, max(right.mx, root->data)), min(right.mn, min(left.mn, root->data)), 1 + left.count + right.count, true);
        }
        
        return info(false);
    }
    
public:
    int largestBst(Node *root) {
    	//Your code here
    	max_count = 0;
    	get_largest_bst(root);
    	return max_count;
    }
};