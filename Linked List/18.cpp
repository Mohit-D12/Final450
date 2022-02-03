// Check if Linked List is Palindrome
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

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

class Solution{
    
    Node* find_middle(Node* head)
    {
        Node* slow = head, *fast = head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL, *next = NULL;
        
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
    bool isPalindrome(Node *head)
    {
        bool flag = true;
        
        Node* mid = find_middle(head);
        
        mid->next = reverse(mid->next);
        
        Node* a = head, *b = mid->next;
        while(a != NULL && b != NULL)
        {
            if (a->data != b->data)
            {
                flag = false;
                break;
            }
            
            a = a->next;
            b = b->next;
        }
        
        mid->next = reverse(mid->next);
        
        return flag;
    }
};
