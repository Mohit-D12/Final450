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
 
void postorderIterative(Node* root) {

    if (root == nullptr) {

        return;
    }
 
    stack<Node*> s;
    s.push(root);
 
    stack<int> out;
 
    while (!s.empty()) {

        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        if (curr->left)
            s.push(curr->left);
 
        if (curr->right)
            s.push(curr->right);
    }
 
    while (!out.empty()) {

        cout << out.top() << " ";
        out.pop();
    }
}