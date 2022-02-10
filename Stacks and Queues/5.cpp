// How to efficiently implement k stacks in a single array
// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/


#include<bits/stdc++.h>
using namespace std;
  
class kStacks
{
    int *arr;   // Array of size n to store actual content to be stored in stacks
    int *top;   // Array of size k to store indexes of top elements of stacks
    int *next;  // Array of size n to store next entry in all stacks
                // and free list
    int n, k;
    int free; // To store beginning index of free list

public:
    kStacks(int k1, int n1)
    {
        k = k1, n = n1;

        arr = new int[n];
        top = new int[k];
        next = new int[n];
    
        for (int i = 0; i < k; i++)
            top[i] = -1;
    
        free = 0;

        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;

        next[n-1] = -1; 
    }

    bool isFull()
    {  
        return (free == -1);  
    }

    bool isEmpty(int sn)
    {  
        return (top[sn] == -1);
    }

    void push(int item, int sn)
    {
        if (isFull())
        {
            cout << "\nStack Overflow\n";
            return;
        }

        int i = free;
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;

        arr[i] = item;

    }

    int pop(int sn)
    {
        if (isEmpty(sn))
        {
            cout << "\nStack Underflow\n";
            return INT_MAX;
        }
    
        int i = top[sn];
    
        top[sn] = next[i]; 
        next[i] = free;
        free = i;
    
        return arr[i];
    }

};
  