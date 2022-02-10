// Segregate even and odd nodes in a Link List
// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even = new Node(-1);
        Node* odd = new Node(-1);
        Node* e = even, *o = odd;
        
        Node* c = head;
        
        while(c)
        {
            if((c->data)&1)
            {
                o->next = c;
                o = o->next;
            }
            else
            {
                e->next = c;
                e = e->next;
            }
            c = c->next;
        }
        
        o->next = NULL;
        e->next = odd->next;
        head = even->next;
        delete odd, even;
        return head;
    }
};