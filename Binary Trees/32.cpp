// min-distance-between-two-given-nodes-of-a-binary-tree
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

struct info {

public:
    int min_dist;
    int nearest_a;
    int nearest_b;
    
    info() {
        
        this->min_dist = INT_MAX;
        this->nearest_a = INT_MAX;
        this->nearest_b = INT_MAX;
    }
    
    info(int min_dist, int nearest_a, int nearest_b) {
        
        this->min_dist = min_dist;
        this->nearest_a = nearest_a;
        this->nearest_b = nearest_b;
    }
};

class Solution {
    
    // pair <dist, num_val_found>
    info solve(Node* root, int a, int b) {
        
        if(!root)
            return info();
        
        info left = solve(root->left, a, b);
        info right = solve(root->right, a, b);
        
        info result;
        
        //a
        if(root->data == a)
            result.nearest_a = 0;
        else if(left.nearest_a != INT_MAX || right.nearest_a != INT_MAX)
            result.nearest_a = min(left.nearest_a, right.nearest_a) + 1;
        
        //b 
        if(root->data == b)
            result.nearest_b = 0;
        else if(left.nearest_b != INT_MAX || right.nearest_b != INT_MAX)
            result.nearest_b = min(left.nearest_b, right.nearest_b) + 1;
        
        //min dist
        result.min_dist = min(left.min_dist, right.min_dist);
        
        if(left.nearest_a != INT_MAX && right.nearest_b != INT_MAX)
            result.min_dist = min(result.min_dist, left.nearest_a + right.nearest_b + 2);
            
        if(left.nearest_b != INT_MAX && right.nearest_a != INT_MAX)
            result.min_dist = min(result.min_dist, left.nearest_b + right.nearest_a + 2);
        
        if(root->data == a) {
            
            if(right.nearest_b != INT_MAX)
                result.min_dist = min(result.min_dist, right.nearest_b + 1);
                
            if(left.nearest_b != INT_MAX)
                result.min_dist = min(result.min_dist, left.nearest_b + 1);
        }
        
        if(root->data == b) {
            
            if(right.nearest_a != INT_MAX)
                result.min_dist = min(result.min_dist, right.nearest_a + 1);
                
            if(left.nearest_a != INT_MAX)
                result.min_dist = min(result.min_dist, left.nearest_a + 1);
        }
        
        return result;
    }
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        
        // Your code here
        info dist = solve(root, a, b);
        
        return dist.min_dist;
    }
};