// Flatten A Linked List
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* bottom;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->bottom = NULL;
	}
};

struct compare {
    
    public:
    bool operator()(Node* a, Node* b) {
        
        return a->data > b->data;
    }
};

// Approach 1: using heap
Node *flatten_efficient(Node *root) {
    
    // Your code here
    priority_queue<Node*, vector<Node*>, compare> pq;
    
    Node* result_head = new Node(-1);
    Node* result_iter = result_head;
    
    Node* main_iter = root;
    Node* min_node;
    
    while(main_iter) {
    
        pq.push(main_iter);
        main_iter = main_iter->next;
    }
    
    while(pq.size()) {
        
        min_node = pq.top();
        pq.pop();
        
        // insert min node in result
        result_iter->bottom = min_node;
        result_iter->next = NULL;
        
        result_iter = min_node;
        
        // insert bottom of min node in pq
        if(min_node->bottom)
            pq.push(min_node->bottom);
    }
       
    return result_head->bottom;
}

// Approach 2: recursion
Node* merge_sorted(Node* a, Node* b)
{
   Node* head = new Node(-1);
   Node* temp = head;
    
   while(a != NULL && b != NULL)
   {
      if(a->data <= b->data)
         {
            temp->bottom = a;
            a = a->bottom;
         }
         else
         {
            temp->bottom = b;
            b = b->bottom;
         }
        temp = temp->bottom;
   }

   if(a != NULL)
      temp->bottom = a;
   else
      temp->bottom = b;
    
   return head->bottom;
}

Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL)
      return root;
    
   return merge_sorted(root, flatten(root->next));
}