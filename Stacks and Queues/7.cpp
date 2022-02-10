// Reverse a string using Stack
// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1#

#include<bits/stdc++.h>
using namespace std;

//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> a;

    for(int i = 0; i < len; i++)
        a.push(S[i]);
        
    for(int i = 0; i < len; i++)
    {
        S[i] = a.top();
        a.pop();
    }
    
    return S;
}