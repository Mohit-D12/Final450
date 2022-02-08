// Merge K sorted linked lists
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

class Solution{
    Node* merge_sorted(Node* a, Node* b)
    {
       Node* head = new Node(-1);
       Node* temp = head;
        
       while(a != NULL && b != NULL)
       {
          if(a->data <= b->data)
             {
                temp->next = a;
                a = a->next;
             }
             else
             {
                temp->next = b;
                b = b->next;
             }
            temp = temp->next;
       }
    
       if(a != NULL)
          temp->next = a;
       else
          temp->next = b;
        
       return head->next;
    }
    
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           while(k > 1)
           {
               for(int i = 0; i< k/2; i++)
                   arr[i] = merge_sorted(arr[i], arr[k - 1 - i]);
               
               k = ceil(k/2.0);
           }
           
           return arr[0];
    }
};