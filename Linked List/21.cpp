// Find pairs with given sum in sorted doubly linked list
// https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/

#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next, *prev;
};
 
void pairSum(struct Node *head, int x)
{
    struct Node *first = head;
    struct Node *second = head;

    while (second->next != NULL)
        second = second->next;
 
    bool found = false;
 
    while (first != second && second->next != first)
    {
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", " << second->data << ")" << endl;
 
            first = first->next;
            second = second->prev;
        }
        else
        {
            if (first->data + second->data < x)
                first = first->next;
            else
                second = second->prev;
        }
    }

    if (found == false)
        cout << "No pair found";
}