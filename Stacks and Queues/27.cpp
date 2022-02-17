// Queue Reversal 
// https://practice.geeksforgeeks.org/problems/queue-reversal/1#

#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    if(q.empty())
        return q;
        
    int val = q.front();
    q.pop();
    q = rev(q);
    q.push(val);
    return q;
}