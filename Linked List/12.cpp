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

int find_len(Node* head)
{
    int count = 0;
    struct Node *curr = head;
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int intersectPoint(Node* head1, Node* head2)
{
    int c1 = find_len(head1);
    int c2 = find_len(head2);
    
    while(c1 > c2)
    {
        head1 = head1->next;
        c1--;
    }
    while(c2 > c1)
    {
        head2 = head2->next;
        c2--;
    }
    
    while(head1 != NULL)
    {
        if(head1 == head2)
            return head1->data;
        
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return -1;
    
}
