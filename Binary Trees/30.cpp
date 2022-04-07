// K Sum Paths
// https://practice.geeksforgeeks.org/problems/k-sum-paths/1/

#include<bits/stdc++.h>
using namespace std;

struct Node  {

    int data;
    Node *left;
    Node *right;

    Node(int val) {

        data = val;
        left = right = NULL;
    }
};

class Solution {
    
    int count;
    multiset<int> h;
    
    void solve(Node* root, int sm, int k) {
        
        if(!root)
            return;
        
        sm += root->data;
        count += h.count(sm - k);
        
        h.insert(sm);
        solve(root->left, sm, k);
        solve(root->right, sm, k);
        h.erase(h.find(sm));
    }
    
  public:
    int sumK(Node *root,int k) {
        
        // code here
        count = 0;
        h.clear();
        h.insert(0);
        solve(root, 0, k);
        
        return count;
    }
};