// Remove duplicate element from sorted Linked List 
// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

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

void removeDuplicates(struct Node* head)
{
    if(head == NULL)
        return;
        
    struct Node* curr = head;
    
    while(curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
            curr = curr->next;
    }
}