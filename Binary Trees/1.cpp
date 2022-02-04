// Level order traversal
// https://practice.geeksforgeeks.org/problems/level-order-traversal/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution
{
    vector<int> levelOrder(Node* node)
    {
        vector<int> result;
        
        if(node == NULL)
            return result;
            
        struct Node* temp = node;
        queue<Node*> nodes;
        nodes.push(node);
        
        while(!nodes.empty())
        {
            temp = nodes.front();
            nodes.pop();
            result.push_back(temp->data);
            
            if(temp->left != NULL)
                nodes.push(temp->left);
            if(temp->right != NULL)
                nodes.push(temp->right);
        }
        
        return result;
    }
};