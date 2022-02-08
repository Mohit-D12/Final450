// Given a linked list of 0s, 1s and 2s, sort it.
// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node* segregate(Node *head) {
        
        Node* h0 = new Node(-1);
        Node* h1 = new Node(-1);
        Node* h2 = new Node(-1);
        
        Node* a = h0, *b = h1, *c = h2, *t = head;
        
        while(t != NULL)
        {
            if(t->data == 0)
            {
                a->next = t;
                a = t;
            }
            else if(t->data == 1)
            {
                b->next = t;
                b = t;
            }
            else
            {
                c->next = t;
                c = t;
            }
            
            t = t->next;
        }
        
        c->next = NULL;
        b->next = h2->next;
        a->next = h1->next;
        head = h0->next;
        
        delete h0, h1, h2;
        return head;
    }
};