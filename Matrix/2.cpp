// Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    auto get_element(vector<vector<int>>& matrix, int index)
    {
        int i = index / matrix[0].size();
        int j = index % matrix[0].size();
    
        return matrix[i][j];
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int s = 0, e = (matrix.size() * matrix[0].size()) - 1;
        int mid = s + (e - s)/2;
        
        while (s <= e)
        {
            if (get_element(matrix, mid) == target)
                return true;
            else if (get_element(matrix, mid) > target)
                e = mid - 1;
            else
                s = mid + 1;
            
            mid = s + (e - s)/2;
        }
        
        return false;
    }
};