// Rat in a Maze Problem - I
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    bool isSafe(vector<vector<int>> &m, vector<string> &ans, vector<vector<bool>> &visited, int n, int i, int j)
    {
        return ((i >= 0 and i < n) && (j >= 0 && j < n) && !visited[i][j] && m[i][j]);
    }
    
    void backtrack(vector<vector<int>> &m, vector<string> &ans, vector<vector<bool>> &visited, int n, int i, int j, string &path)
    {
        //base case
        if(i == n-1 && j == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        visited[i][j] = 1;
        
        int x, y;
        
        //down
        x = i + 1;
        y = j;
        if(isSafe(m, ans, visited, n, x, y))
        {
            path.push_back('D');
            backtrack(m, ans, visited, n, x, y, path);
            path.pop_back();
        }
        
        //right
        x = i;
        y = j + 1;
        if(isSafe(m, ans, visited, n, x, y))
        {
            path.push_back('R');
            backtrack(m, ans, visited, n, x, y, path);
            path.pop_back();
        }
        //up
        x = i - 1;
        y = j;
        if(isSafe(m, ans, visited, n, x, y))
        {
            path.push_back('U');
            backtrack(m, ans, visited, n, x, y, path);
            path.pop_back();
        }
        //left
        x = i;
        y = j - 1;
        if(isSafe(m, ans, visited, n, x, y))
        {
            path.push_back('L');
            backtrack(m, ans, visited, n, x, y, path);
            path.pop_back();
        }
        
        visited[i][j] = 0;
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0)
            return ans;
        
        vector<vector<bool>> visited;
        for(int i = 0; i < n; i++)
        {
            vector<bool> row(n, 0);
            visited.push_back(row);
        }
            
        string path = "";
        backtrack(m, ans, visited, n, 0, 0, path);
        return ans;
    }
    
};
