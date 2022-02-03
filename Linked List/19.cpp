// Deletion from a Circular Linked List
// https://www.geeksforgeeks.org/deletion-circular-linked-list/

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

void deleteNode(Node* head, int key)
{
    if (head == NULL)
        return;
         
    if(head->data == key && head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
     
    Node *last = head, *d;
     
    if(head->data == key)
    {
        while(last->next != head)
            last = last->next;

        last->next = head->next;
        free(head);
        head = last->next;
        return;
    }
     
    while(last->next != head && last->next->data != key)
    {
        last = last->next;
    }
     
    if(last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
        cout << "no such keyfound";
        
}