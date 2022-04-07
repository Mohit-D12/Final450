// Preorder Iterative

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

void preorderIteratve(Node* root) {

    if(!root)
        return;
    
    stack<Node*> s;
    s.push(root);

    while(s.size()) {

        cout << root->data << ' ';

        if(root->left)
            s.push(root->right);
        if(root->right)
            s.push(root->left);
    }
}

void preorderIterativeOptimised(Node* root) {

    if (root == nullptr)
        return;
 
    stack<Node*> stack;
    stack.push(root);
 
    Node* curr = root;
 
    while (!stack.empty()) {

        if (curr != nullptr) {

            cout << curr->data << " ";
 
            if (curr->right)
                stack.push(curr->right);
 
            curr = curr->left;
        }
        else {

            curr = stack.top();
            stack.pop();
        }
    }
}