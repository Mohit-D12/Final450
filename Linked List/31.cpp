// Merge K sorted linked lists
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare
{
   bool operator() (ListNode* a,  ListNode* b)
   {
      return a->val > b->val;
   }
};

class Solution {
    
  public:   
   ListNode* mergeKLists(vector<ListNode*>& lists) {
      
      ListNode* head = new ListNode(-1);
      ListNode* node;
      
      priority_queue<ListNode*, vector<ListNode*>, compare> q;
      
      for(auto node: lists)
         if(node)
               q.push(node);
      
      node = head;
      while(q.size()) {
      
         node->next = q.top();
         q.pop();
         
         node = node->next;
         
         if(node->next)
               q.push(node->next);
      }
      
      return head->next;
   }
};

//Approach 2 
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