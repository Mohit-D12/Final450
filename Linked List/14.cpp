// Quick Sort on Linked List
// https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1#

#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

void quickSort(struct node **result) {
    if(*result == NULL || (*result)->next == NULL)
        return;
        
    struct node* head = *result;
    struct node* sh = new node(-1), *s = sh;
    struct node* gh = new node(-1), *g = gh;
    
    struct node* curr = head->next;
    while(curr)
    {
        if(curr->data <= head->data)
        {
            s->next = curr;
            s = s->next;
        }
        else
        {
            g->next = curr;
            g = g->next;
        }
        
        curr = curr->next;
    }
    
    g->next = NULL;
    head->next = NULL;
    s->next = NULL;
    
    curr = sh;
    sh = sh->next;
    delete curr;
    
    curr = gh;
    gh = gh->next;
    delete curr;
    
    quickSort(&gh);
    quickSort(&sh);
    
    if(sh != NULL)
    {
        curr = sh;
        while(curr->next)
            curr = curr->next;
        
        curr->next = head;
    }
    else
        sh = head;
    
    head->next = gh;
    
    *result = sh;
}