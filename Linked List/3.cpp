// Detect Loop in linked list
// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

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


class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};