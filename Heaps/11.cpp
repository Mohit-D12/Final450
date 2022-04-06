// Smallest range in K lists
// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1#

#include<bits/stdc++.h>
using namespace std;

#define N 1000

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

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        priority_queue<info, vector<info>, compare> q;
        int l, r = INT_MIN, a, b;
        
        //fill first elements into the heap;
        for(int i = 0; i < k; i++) {
            
            q.push(info(KSortedArray[i][0], i, 0));
            r = max(r, KSortedArray[i][0]);
        }
        l = q.top().val;
        b = r;
        
        while(q.size()) {
            
            info temp = q.top();
            q.pop();
            
            if(temp.col == n - 1)
                break;
                
            temp.col++;
            temp.val = KSortedArray[temp.row][temp.col];
            q.push(temp);
            
            a = q.top().val;
            b = max(b, temp.val);
            
            if(b - a < r - l) {
                
                l = a;
                r = b;
            }
        }
        
        return {l, r};
    }
};