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

class Solution_Space_O_N {
    
    bool isPallindromeHelper(Node* curr, Node*& head) {
        
        if(!curr)
            return true;
        
        if(!isPallindromeHelper(curr->next, head))
            return false;
        
        
        bool result =  curr->data == head->data;
        head = head->next;
        return result;
    }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(!head)
            return true;
            
        return isPallindromeHelper(head, head);
    }
};

class Solution_constant_space{
    
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
