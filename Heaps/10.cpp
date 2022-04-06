// Merge K sorted linked lists
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

#include<bits/stdc++.h>
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

struct compare {
    
    public:
    bool operator()(Node* a, Node* b) {
        
        return a->data > b->data;
    }
};

class Solution {
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K) {
        
        priority_queue<Node*, vector<Node*>, compare> q;
        
        Node* head = new Node(-1);
        Node* curr = head, *temp;
        
        for(int i = 0; i < K; i++) {
            
            q.push(arr[i]);
        }
        
        while(q.size()) {
            
            curr->next = q.top();
            curr = curr->next;
            q.pop();
            
            if(curr->next)
                q.push(curr->next);
        }
        
        curr->next = NULL;
        
        return head->next;
    }
};