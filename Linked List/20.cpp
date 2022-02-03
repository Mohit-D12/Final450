// Reverse a Doubly Linked List
// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

Node* reverseDLL(Node * head)
{
    struct Node* curr = head;
    
    while(curr != NULL)
    {
        swap(curr->next, curr->prev);
        
        head = curr;
        curr = curr->prev;
    }
    return head;
}