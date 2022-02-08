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