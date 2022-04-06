// Is Binary Tree Heap
// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#

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
    
    pair<bool, int> solve(struct Node* root) {
        
        if(!root)
            return {true, 0};
            
        pair<bool, int> left = solve(root->left);
        
        if(!left.first)
            return left;
        
        pair<bool, int> right = solve(root->right);
        
        
        if(!right.first)
            return right;
        
        pair<bool, int> result = {true, left.second + right.second + 1};
        
        if(root->left && root->data < root->left->data)
            result.first = false;
        else if(root->right && root->data < root->right->data)
            result.first = false;
        else if(left.second < right.second)
            result.first = false;
        
        return result;
    }    
    
  public:
    bool isHeap(struct Node* tree) {
        
        return solve(tree).first;
    }
};

class Solution_LOT {
    public:

    bool isHeap(Node* root)
    {
        queue<Node*> q;
        q.push(root);

        // nullish represents if any node with less than 2 children has been encountered yet. if yes, no further nodes in LOT can have a child.
        bool nullish = false;       
        while (!q.empty()) {

            Node* temp = q.front();
            q.pop();
            if (temp->left) {

                if (nullish || temp->left->data > temp->data)
                    return false;

                q.push(temp->left);
            }
            else
                nullish = true;
                
            if (temp->right) {

                if (nullish || temp->right->data > temp->data)
                    return false;
                
                q.push(temp->right);
            }
            else
                nullish = true;
        }
        return true;
    }    
};