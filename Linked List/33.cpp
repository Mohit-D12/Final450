// Delete nodes having greater value on right
// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

#include<bits/stdc++.h>
using namespace std;

class Recursive_Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(!(head))
            return head;
        
        Node* temp = compute(head->next);
        if(temp && head->data < temp->data){
            delete head;
            return temp;
        }
       
        head->next = temp;
        return head;
    }
};

class Iterative_Solution
{
  public:
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        Node* temp = head;
        
        while(temp && temp->next)
        {
            if(temp->next->data < temp->data)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        
        return reverse(head);
    }

    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL, *next = NULL;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};


class Node
{
  public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};