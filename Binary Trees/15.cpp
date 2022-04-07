// Diagonal Traversal of Binary Tree 
// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> result;
    queue<Node*> Q;
    Node *p;
    Q.push(root);
    while (!Q.empty())
    {
        p=Q.front();
        Q.pop();
        while (p)
        {
            if(p->left)
                Q.push(p->left);
            result.push_back(p->data);
            p=p->right;
        }
    }
    
    return result;
}