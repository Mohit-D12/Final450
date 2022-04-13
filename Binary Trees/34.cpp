// Find Duplicates Subtrees
// https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1#

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left, *right;
};

string solve(Node* root, unordered_map<string, int>& h, vector<Node*>& result) {
    
    if(!root)
        return "N";
    
    string hash = to_string(root->data) + " ";
    hash += solve(root->left, h, result) + " ";
    hash += solve(root->right, h, result);
    
    if(h[hash] == 1)
        result.push_back(root);
        
    h[hash]++;
    return hash;
}


vector<Node*> printAllDups(Node* root)
{
    // Code here
    unordered_map<string, int> h;
    vector<Node*> result;
    solve(root, h, result);
    
    return result;
}