// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

int findLevel(Node *root, int k, int level) {

    if (root == NULL) 
        return -1;
    if (root->data == k) 
        return level;

    int l = findLevel(root->left, k, level + 1);
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}

Node *findDistU(Node *root, int n1, int n2, int &d1, int &d2, int &dist, int lvl) {

    if (root == NULL) 
        return NULL;

    if (root->data == n1) {

        d1 = lvl;
        return root;
    }

    if (root->data == n2) {

        d2 = lvl;
        return root;
    }

    Node *l = findDistU(root->left, n1, n2, d1, d2, dist, lvl + 1);
    Node *r = findDistU(root->right, n1, n2, d1, d2, dist, lvl + 1);

    if (l and r)
        dist = d1 + d2 - 2 * lvl;
        
    return (l != NULL) ? l : r;
}

class Solution {
    
    public:
    int findDist(Node *root, int n1, int n2) {

        int d1 = -1, d2 = -1, dist;
        Node *lca = findDistU(root, n1, n2, d1, d2, dist, 1);

        if (d1 != -1 and d2 != -1)
            return dist;

        if (d1 != -1)
            dist = findLevel(lca, n2, 0);
            return dist;

        if (d2 != -1)
            dist = findLevel(lca, n1, 0);
            return dist;
            
        return -1;
    }
};