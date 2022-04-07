// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node *left, *right;
 
    Node(int data) {

        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
void inorderIterative(Node* root) {
    
    stack<Node*> stack;
    Node* curr = root;
 
    while (!stack.empty() || curr != nullptr) {

        if (curr != nullptr) {

            stack.push(curr);
            curr = curr->left;
        }
        else {

            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}