// Median of a BST
// https://practice.geeksforgeeks.org/problems/median-of-bst/1/#

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

int count_nodes(Node* root) {

    //morris traversal
    int count = 0;
    Node* pred;

    while(root) {

        if(root->left == NULL) {
            
            count++;
            root = root->right;
            continue;
        }
        
        pred = root->left;

        while(pred->right != NULL && pred->right != root) 
            pred = pred->right;

        if(pred->right == NULL) {

            count++;
            pred->right = root;
            root = root->left;
        }
        else {

            pred->right = NULL;
            root = root->right;
        }
    }

    return count;
}

pair<Node*, Node*> get_kth_smallest(Node* root, int k) {

    int count = 0;
    Node* pred;
    Node* mid1 = NULL, *mid2 = NULL;

    while(root) {

        if(root->left == NULL) {
            
            count++;
            
            if(count == k - 1)
                mid1 = root;
                
            if(count == k)
                mid2 = root;
                
            root = root->right;
            continue;
        }
        
        pred = root->left;

        while(pred->right != NULL && pred->right != root) 
            pred = pred->right;

        if(pred->right == NULL) {

            pred->right = root;
            root = root->left;
        }
        else {

            count++;
            
            if(count == k - 1)
                mid1 = root;
            
            if(count == k)
                mid2 = root;
                
            pred->right = NULL;
            root = root->right;
        }
    }

    return {mid1, mid2};
}

float findMedian(struct Node *root)
{
    //Code here
    int n = count_nodes(root);
    int k = n/2 + 1;

    pair<Node*, Node*> mids = get_kth_smallest(root, k);
    
    
    if(n & 1) 
        return mids.second->data;

    return (mids.first->data + mids.second->data) / 2.0;
    
    return 0.0;
}