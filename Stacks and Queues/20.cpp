// Stack using two queues
// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#

#include<bits/stdc++.h>
using namespace std;

class QueueStack
{
  private:
    queue<int> q1;
    queue<int> q2;

  public:
    void push(int x)
    {
        // Your Code
        while(!q2.empty())
            q2.pop();
            
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(x);
        while(q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        // Your Code  
        if (q1.empty())
            return -1;

        int val = q1.front();
        q1.pop();

        return val;
    }
};