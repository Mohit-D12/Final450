
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
};

struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}
 
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
        return;
 
    root->data = arr[++*i];
    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}
 
void convertToMinHeapUtil(Node* root)
{
    vector<int> arr;
    int i = -1;
 
    inorderTraversal(root, arr);
    BSTToMinHeap(root, arr, &i);
}