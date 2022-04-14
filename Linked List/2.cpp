// Reverse a Linked List in groups of given size.
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

//RECURSIVE SOLUTION
class Solution
{
    
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(!head)
            return NULL;
        
        int count = 0;
        node* curr = head, *prev = NULL, *next = NULL;
        
        while(count++ < k && curr) {
            
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        head->next = reverse(curr, k);
        return prev;
    }
};


//ITERATIVE SOLUTION
struct node* kReverse(struct node* head, int k) {
    
    if(k == 1 || head->next == NULL)
        	return head;
    
    struct node *pc = new struct node(-1), *pct = NULL, *prev = NULL, *curr = head, *next = NULL;
    int count = 0;
    bool flag = true;
    
    while(curr != NULL)
    { 
        if(curr->next == NULL)
        {
            //last node
            if(flag)
            {
                head = curr;
                flag = false;
            }
            if(count == 0)
                pc->next = curr;
            else
            {
                curr->next = prev;
                pc->next = curr;
                pct->next = NULL;
            }
        	break;    
        }
        else if(count == 0)
        {
            pct = curr;
            prev = curr;
            curr = curr->next;
        }
        else if(count == k - 1)
        {
            if(flag)
            {
               	head = curr;
                flag = false;
            }
            next = curr->next;
            curr->next = prev;
            pc->next = curr;
            pc = pct;
            
            curr = next;
        }
        else
        {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        count = (count+1)%k;
    }
    
    return head;
    
}