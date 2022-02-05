// Merge Sort for Linked List
// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

node* merge(node* a, node* b)
{   
    node* head = new node(-1);
    node* temp = head;
    
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
    
    temp = head;
    head = head->next;
    delete temp;
    return head;
}

node* mergeSort(node *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL)
        	return head;
    
    node* a = head, *b = head->next;
    
    while(b != NULL && b->next != NULL)
    {
        a = a->next;
        b = b->next->next;
    }
    
    b = a->next;
    a->next = NULL;
    
    a = mergeSort(head);
    b = mergeSort(b);
    head = merge(a, b);
    
    return head;
}
