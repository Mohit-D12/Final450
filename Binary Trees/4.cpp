#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node* left;
    Node* right;
};

class Solution {
    int find_diameter(struct Node* node, int& d)
    {
        if(node == NULL)
            return 0;
        
        int left = find_diameter(node->left, d);
        int right = find_diameter(node->right, d);
        
        d = max(d, left + right + 1);
        
        return 1 + max(left, right);
    }
    
  public:
    int diameter(Node* root) {
        int d = 0;
        find_diameter(root, d);
        return d;
    }
};