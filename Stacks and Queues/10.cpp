// The Celebrity Problem 
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    bool is_celeb(int c, vector<vector<int> >& M, int n)
    {
        for(int i = 0; i < n; i++)
            if(M[c][i])
                return false;
            
        for(int i = 0; i < n; i++)
            if(!(M[i][c] || i==c))
                return false;
            
        return true;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int c = 0;
        for(int i = 1; i < n; i++)
        {
            if (M[c][i] && !M[i][c])
                c = i;
            else if (M[i][c] && !M[c][i])
                continue;
            else
                c = ++i;
        }
        
        if(c < n && is_celeb(c, M, n))
            return c;
        
        return -1;
    }
};