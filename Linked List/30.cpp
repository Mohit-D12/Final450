// Clone a linked list with next and random pointer 
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
    Node* copy_and_merge(Node* head)
    {
        Node* a = head;
        Node* b;
        
        while(a != NULL)
        {
            b = new Node(a->data);
            b->next = a->next;
            a->next = b;
            
            a = b->next;
        }
    }
    
    void update_arb(Node* head)
    {
        Node* a = head;
        
        while(a != NULL)
        {
            if(a->arb != NULL)
                a->next->arb = a->arb->next;
            
            a = a->next->next;
        }
    }
    
    Node* split_alternate(Node* head)
    {
        if(head == NULL)
            return NULL;
            
        Node* result = head->next;
        
        Node* a = head;
        Node* temp;
        
        while(a->next != NULL)
        {
            temp = a->next;
            a->next = temp->next;
            a = temp;
        }
        
        return result;
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here

        if(head == NULL)
            return NULL;
        
        copy_and_merge(head);
        update_arb(head);
        
        return split_alternate(head);
    }

};