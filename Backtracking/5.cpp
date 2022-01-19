// Solve the Sudoku
// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1#

#include<bits/stdc++.h>
using namespace std;

#define N 5

class Solution 
{
    bool is_safe(int (*grid)[N], int x, int y, int k)
    {
        for(int i = 0; i < 9; i++)
        
            if (grid[x][i] == k || grid[i][y] == k)
                return false;
        
        int bx = x - x%3;
        int by = y - y%3;
        
        for(int i = bx; i < bx+3; i++)
        {
            for(int j = by; j < by+3; j++)
            {
                if (grid[i][j] == k)
                    return false;
            }
        }
        
        return true;
    }
    
    bool backtrack(int (*grid)[N], int x, int y)
    {
        if (y == N)
        {
            x++;
            y = 0;
        }
        
        if (x == N)
            return true;
            
        if (grid[x][y] > 0)
            return backtrack(grid, x, y+1);
            
        bool result = false;
        
        
        for (int i = 1; i < 10; i++)
        {
            if (is_safe(grid, x, y, i))
            {
                grid[x][y] = i;
                
                result = backtrack(grid, x, y+1);
                if (result)
                    return result;
                    
                grid[x][y] = 0;
            }
        }
        // cout << x << " " << y << endl;
        return result;
            
    }
    
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int x0 = 0, y0 = 0;
        bool result = backtrack(grid, x0, y0);
        return result;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
        
        };
    }
};