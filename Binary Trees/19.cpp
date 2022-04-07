// Transform to Sum Tree
// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
    
    int fill_sum(Node* root) {
        
        if(!root)
            return 0;
            
        int sm = fill_sum(root->left);
        sm += fill_sum(root->right);
        
        int val = sm + root->data;
        root->data = sm;
        return val;
    }
    
  public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        fill_sum(node);
    }
};