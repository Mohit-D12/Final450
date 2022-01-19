// Spirally traversing a matrix
// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int u = 0, d = r - 1;
        int x = 0, y = c - 1;
        
        int count = 0;
        
        while (count < r*c)
        {
            for(int i = x; i <= y && count < r*c; i++)
            {
                ans.push_back(matrix[u][i]);
                count++;
            }
            u++;
            for(int i = u; i <= d && count < r*c; i++)
            {
                ans.push_back(matrix[i][y]);
                count++;
            }
            y--;
            for(int i = y; i >= x && count < r*c; i--)
            {
                ans.push_back(matrix[d][i]);
                count++;
            }
            d--;
            for(int i = d; i >= u && count < r*c; i--)
            {
                ans.push_back(matrix[i][x]);
                count++;
            }
            x++;
        }
        
        return ans;
    }
};