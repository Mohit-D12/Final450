// Sort a stack
// https://practice.geeksforgeeks.org/problems/sort-a-stack/1#

#include<bits/stdc++.h>
using namespace std;

class SortedStack
{
  public:
	stack<int> s;

    void sort()
    {
        if(s.empty())
            return;
        
        int val = s.top();
        s.pop();
        sort();
        insert_sorted(val);
    }

  private:
    void insert_sorted(int val)
    {
        if(s.empty() || s.top() <= val)
        {
            s.push(val);
            return;
        }
        
        int temp = s.top();
        s.pop();
        insert_sorted(val);
        s.push(temp);
    }
};