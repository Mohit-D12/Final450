// Find first node of loop in a linked list
// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

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


Node* find_first_node_of_loop(Node* head)
{
    Node* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    if(slow != fast)
        return NULL;
    
    slow = head;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;    
}