// Intersection of two sorted Linked lists
// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2)
{
    struct Node *res = new Node(0);
    struct Node *a = head1, *b = head2, *c = res;
    while(a != NULL && b != NULL)
    {
        while(a != NULL && a->data < b->data)
            a = a->next;
        while(b != NULL && b->data < a->data)
            b = b->next;
        
        if(a != NULL && b != NULL && a->data == b->data)
        {
            c->next = new struct Node(a->data);
            a = a->next;
            b = b->next;
            c = c->next;
        }
    }
    return res->next;
}