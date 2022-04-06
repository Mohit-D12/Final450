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

class Solution_unefficient_space {
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


class Solution_constant_space {
    
    Node* merge(Node* a, Node* b) {
        
        Node* head = new Node(-1);
        Node* curr = head;
        
        while(a && b) {
            
            if(a->data < b->data) {
                
                curr->next = a;
                a = a->next;
            }
            else {
                
                curr->next = b;
                b = b->next;
            }
            
            curr = curr->next;
        }
        if(a) 
            curr->next = a;
        else 
            curr->next = b;
            
        return head->next;
    }
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k) {
        
        while(k > 1) {
            
            int i = 0;
            while((i << 1) < k) {
                
                if((i << 1) + 1 < k)
                    arr[i] = merge(arr[(i << 1)], arr[(i << 1) + 1]);
                else
                    arr[i] = arr[(i << 1)];
                
                i++;
            }   
            
            k = (k + 1)>>1;
        }
        
        return arr[0];
    }
};