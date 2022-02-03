// Check If Circular Linked List
// https://practice.geeksforgeeks.org/problems/circular-linked-list/1#

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

bool isCircular(Node *head)
{
   if(head == NULL)
        return true;
    
    struct Node* temp;
    
    while (temp != NULL)
    {
        temp = temp->next;
        if(temp == head)
            return true;
    }
    
    return false;
}