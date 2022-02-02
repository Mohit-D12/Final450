// Remove loop in Linked List
// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

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
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        //detect loop
        Node* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        //loop present
        if(slow == fast)
        {
            slow = head;

            //case where linked list is circular (loop from last node to first node)
            if(slow == fast) 
            {
                while(fast->next != slow) 
                {
                    fast = fast->next;
                }
            }
            else
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            //fast now points to the end of the loop
            fast->next = NULL;
    
        }
        
    }
};