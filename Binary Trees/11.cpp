// Top View of Binary Tree
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  public:
    int data;
    struct Node* left;
    struct Node* right;
};

struct info {

  public:
    Node* node;
    int level;
    
    info(Node* node, int level) {
        
        this->node = node;
        this->level = level;
    }
};
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int, int> h;
        
        //lot
        queue<info> q;
        q.push(info(root, 0));
        
        while(q.size()) {
            
            info temp = q.front();
            q.pop();
            
            if(h.find(temp.level) == h.end())
                h[temp.level] = temp.node->data;
            
            if(temp.node->left)
                q.push(info(temp.node->left, temp.level - 1));
            if(temp.node->right)
                q.push(info(temp.node->right, temp.level + 1));
        }
        
        vector<int> result;
        
        for(auto i: h)
            result.push_back(i.second);
            
        return result;
    }

};