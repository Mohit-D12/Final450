// pred and succ of a node
// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& p, Node*& q, int a)
{
    // If root is null return
    if(!root)
        return ;
         
    // traverse the left subtree   
    findPreSuc(root->left, p, q, a);
     
    // root data is greater than a
    if(root&&root->key > a)
    {
         
        // q stores the node whose data is greater
        // than a and is smaller than the previously
        // stored data in *q which is successor
        if((!q) || (q) && (q)->key > root->key)
                q = root;
    }
     
    // if the root data is smaller than
    // store it in p which is predecessor
    else if(root && root->key < a)
    {
        p = root;
    }
     
    // traverse the right subtree
    findPreSuc(root->right, p, q, a);
}