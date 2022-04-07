// kth ancestor
// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/

#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 
Node* temp = NULL;
 
Node* kthAncestorDFS(Node *root, int node , int &k)
{  
    if (!root)
        return NULL;
     
    if (root->data == node||
       (temp =  kthAncestorDFS(root->left,node,k)) ||
       (temp =  kthAncestorDFS(root->right,node,k)))
    {  
        if (k > 0)       
            k--;
         
        else if (k == 0)
        {
            cout<<"Kth ancestor is: "<<root->data;
            return NULL;
        }
         
        return root;
    }
}