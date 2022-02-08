// Split a Circular Linked List into two halves
// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head, *fast = head->next, *prev = head;

    while(fast != head && fast->next != head)
    {
        slow = slow->next;
        prev = fast->next;
        fast = fast->next->next;
    }
    
    while(prev->next != head)
        prev = prev->next;

    
    *head1_ref = head;
    *head2_ref = slow->next;
    
    slow->next = *head1_ref;
    prev->next = *head2_ref;
}