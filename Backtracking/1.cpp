// Rat in a Maze Problem - I
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<bits/stdc++.h>
using namespace std;

class Solution{

    vector<string> result;
    string path;
    
    void findPathUtil(vector<vector<int>>& m, int n, int i, int j) {
        
        if(i == -1 || j == -1 || i == n || j == n || m[i][j] != 1)
            return;
            
        if(i == n - 1 && i == j) {
            
            result.push_back(path);
            return;
        }
        
        m[i][j] = 2;
        
        int sz = path.size();
        
        path.push_back('U');
        findPathUtil(m, n, i - 1, j);
        
        path[sz] = 'D';
        findPathUtil(m, n, i + 1, j);
        
        path[sz] = 'L';
        findPathUtil(m, n, i, j - 1);
        
        path[sz] = 'R';
        findPathUtil(m, n, i, j + 1);
        
        path.pop_back();
        m[i][j] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        result.clear();
        path = "";
        
        if(m[0][0] == 0 || m[n - 1][n - 1] == 0)
            return result;
        
        findPathUtil(m, n, 0, 0);
        return result;
    }
};