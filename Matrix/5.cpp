// Sorted matrix
// https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1#

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat) {
        // code here
        
        int* temp = new int[n*n];
        int k = 0;
    
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp[k++] = mat[i][j];
    
        sort(temp, temp + k);
        
        k = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = temp[k++];
        
        delete[] temp;
        return mat;
    }
};