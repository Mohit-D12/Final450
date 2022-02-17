// Queue using two Stacks
// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> a, b;
    
  public:
    MyQueue() {
    }
    
    void push(int x) {
        while(!b.empty())
            b.pop();
        
        while(!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        
        a.push(x);
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
    }
    
    int pop() {
        int val = a.top();
        a.pop();
        return val;
    }
    
    int peek() {
        return a.top();
    }
    
    bool empty() {
        return a.empty();    
    }
};
