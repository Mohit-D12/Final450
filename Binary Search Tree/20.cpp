// Check for dead end
// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node * right, * left;
};

bool solve(Node* root, int low, int high) {
    
    if(!root)
        return false;
    
    if(low == high)
        return true;
    
    return solve(root->left, low, root->data - 1) || solve(root->right, root->data + 1, high);
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    
    return solve(root, 1, INT_MAX);
}