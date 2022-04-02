// Merge 2 bst into vector
// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/#

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    Node* flatten(Node* root, Node* next = NULL) {
        
        if(!root) {
            return root;
        }
        
        Node* head = root;
        if(root->left)
            head = flatten(root->left, root);
            
        if(root->right)
            root->right = flatten(root->right, next);
        else
            root->right = next;
            
        if(root->right)
            root->right->left = root;
        
        return head;
    }
    
    Node* mergeDll(Node* h1, Node* h2) {
        
        Node* a = h1, *b = h2;
        Node* head = new Node(-1);
        Node* c = head;
        
        while(a && b) {
            
            if(a->data <= b->data) {
                
                c->right = a;
                a = a->right;
            }
            else {
                
                c->right = b;
                b = b->right;
            }
            
            c = c->right;
        }
        
        if(a)
            c->right = a;
        else
            c->right = b;
        
        return head->right;
    }
    
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       
       //step 1: flatten bst
       Node* head1 = flatten(root1);
       Node* head2 = flatten(root2);
       
       //step 2: merge the lists
       Node* head = mergeDll(head1, head2);
       
       //step 3: built bst
       vector<int> result;
       Node* it = head;
       while(it) {
           
           result.push_back(it->data);
           it = it->right;
       }
       
       return result;
    }
};