// Intersection Point in Y Shapped Linked Lists
// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; 

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* a = head1, *b = head2;
    
    while(a && b) {
        
        a = a->next;
        b = b->next;
        
        if(!a && !b)
            return -1;
            
        if(a == b)
            return a->data;
        
        if(!a)
            a = head2;
        if(!b)
            b = head1;
    }
}