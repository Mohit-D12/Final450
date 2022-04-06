// Merge two binary Max heaps
// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

#include<bits/stdc++.h>
using namespace std;

class Solution_make_heap{   // O(N)
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        vector<int> result(a);
        for(auto i: b)
            result.push_back(i);
        
        make_heap(result.begin(), result.end());
        return result;
    }
};
class Solution_push_repeated{     // O(N LogN)
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        vector<int> result(a);
        
        for(int i = 0; i < m; i++) {
            
            result.push_back(b[i]);
            push_heap(result.begin(), result.end());
        }
        
        return result;
    }
};

