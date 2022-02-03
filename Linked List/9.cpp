// Add 1 to a number represented as linked list 
// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include<bits/stdc++.h>
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

class Solution
{
    Node* reverse(Node* head)
    {
        struct Node* curr = head;
        struct Node *prev = NULL, *next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
    
            prev = curr;
            curr = next;
        }
    
        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        if(head == NULL)
            return new struct Node(1);
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        
        struct Node *curr = head, *prev = NULL;
        int carry = 1;
        while(curr != NULL)
        {
            curr->data += carry;
            carry = curr->data / 10;
            curr->data %= 10;
            
            prev = curr;
            curr = curr->next;
        }
        
        if(carry)
            prev->next = new struct Node(carry);
        
        head = reverse(head);
        return head;
    }
};