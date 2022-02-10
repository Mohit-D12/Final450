// Balanced Parenthesis Checker
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool ispar(string x)
    {
        // Your code here
        stack<char> b;
        
        for(char ch: x)
        {
            if(ch == '{' || ch == '(' || ch == '[')
                b.push(ch);
                
            else if(!b.empty() && ((ch == '}' && b.top() == '{') || (ch == ')' && b.top() == '(') || (ch == ']' && b.top() == '[')))
                b.pop();
            
            else
                return false;
                
        }
        
        return b.empty();
    }

};