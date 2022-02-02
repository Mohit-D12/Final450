// Reverse a linked list
// https://www.geeksforgeeks.org/reverse-a-linked-list/

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


Node* reverse_linked_list(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}