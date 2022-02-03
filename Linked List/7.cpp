// Remove duplicates from an unsorted linked list
// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    type data;
    struct Node* next;

    Node(type data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(type data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        if(head == NULL)
            return head;
        
        unordered_set<int> k;
        
        struct Node* curr = head;
        
        while(curr->next != NULL)
        {
            k.insert(curr->data);
            if(k.find(curr->next->data) != k.end())
                curr->next = curr->next->next;
            else
                curr = curr->next;
            
        }
        
        return head;
    }
};