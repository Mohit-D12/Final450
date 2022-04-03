// Brothers From Different Roots 
// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BSTIteratorForward {
    
    stack<Node*> route;
    
public:
    BSTIteratorForward(Node* root) {
        
        while(root) {
            
            route.push(root);
            root = root->left;
        }
    }
    
    
    int peek() {
        
        if(!this->hasNext())
            return -1;
        
        return (route.top())->data;
    }
    
    int getNext() {
        
        if (!this->hasNext())
            return -1;
        
        Node* e = route.top();
        route.pop();
        
        Node* r = e->right;
        while(r) {
            
            route.push(r);
            r = r->left;
        }
        
        return e->data;
    }
    
    bool hasNext() {
        
        return route.size();
    }
};
class BSTIteratorBackward {
    
    stack<Node*> route;
    
public:
    BSTIteratorBackward(Node* root) {
        
        while(root) {
            
            route.push(root);
            root = root->right;
        }
    }
    
    int peek() {
        
        if(!this->hasNext())
            return -1;
        
        return (route.top())->data;
    }
    
    int getNext() {
        
        if (!this->hasNext())
            return -1;
        
        Node* e = route.top();
        route.pop();
        
        Node* r = e->left;
        while(r) {
            
            route.push(r);
            r = r->right;
        }
        
        return e->data;
    }
    
    bool hasNext() {
        
        return route.size();
    }
};

class Solution {
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        BSTIteratorForward i(root1);
        BSTIteratorBackward j(root2);
        
        int pairs = 0;
        
        while(i.hasNext() && j.hasNext()) {
            
            if(i.peek() + j.peek() == x) {
                
                pairs++;
                i.getNext();
                j.getNext();
            }
            
            else if(i.peek() + j.peek() < x)
                i.getNext();
            
            else 
                j.getNext();
        }
        
        return pairs;
        
    }
};