// Insert At bottom of a stack

#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> s, int val)
{
    if(s.empty())
        s.push(val);

    else
    {
        int a = s.top();
        s.pop();
        
        insert_at_bottom(s, val);
        s.push(a);
    }
}