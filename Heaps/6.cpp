// Merge sorted Arrays
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

#include<bits/stdc++.h>
using namespace std;

struct info {

public:
    int val, row, col;
    
    info(int val, int row, int col) {
        
        this->val = val;
        this->row = row;
        this->col = col;
    }
};

struct compare {
    
public:
    bool operator()(info& a, info& b) {
        
        return a.val > b.val;
    }
};


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        
        int n = arr.size();
        priority_queue<info, vector<info>, compare> q;
        vector<int> result;
        
        //fill first elements into the heap;
        for(int i = 0; i < n; i++) {
            
            q.push(info(arr[i][0], i, 0));
        }
        
        while(q.size()) {
            
            info temp = q.top();
            q.pop();
            
            result.push_back(temp.val);
            
            if(temp.col < K - 1) {
                
                temp.col++;
                temp.val = arr[temp.row][temp.col];
                q.push(temp);
            }
        }
        
        return result;
    }
};