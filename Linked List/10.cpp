// Add two numbers represented by linked lists 
// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    struct Node* reverse(struct Node* head)
    {
        struct Node* curr = head, *prev = NULL, *next = NULL;
        
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
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        int sum, carry = 0;
        struct Node* res = new Node(-1);
        struct Node *a = first, *b = second, *c = res;
        
        while(a != NULL || b != NULL || carry)
        {
            int x = 0, y = 0;
            
            if(a != NULL){
                x = a->data;
                a = a->next;
            }
            if(b != NULL){
                y = b->data;
                b = b->next;
            }
                
            sum = x + y + carry;
            carry = sum / 10;
            sum %= 10;
            
            c->next = new Node(sum);
            c = c->next;
        }
            
        res = res->next;
        
        reverse(first);
        reverse(second);
        
        return reverse(res);
    }
};