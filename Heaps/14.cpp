// Minimum Cost of ropes
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

class Solution_make_heap {
    
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        make_heap(arr, arr+n, greater<long long int>());
        
        
        long long int result = 0;
        long long int x;
        
        while(n > 1) {
            
            x = arr[0];
            pop_heap(arr, arr + n--, greater<long long int>());
            
            x += arr[0];
            pop_heap(arr, arr + n, greater<long long int>());
            
            result += x;
            arr[n - 1] = x;
            push_heap(arr, arr + n, greater<long long int>());
        }
        
        return result;
    }
};

class Solution_priority_queue {

    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        priority_queue<long long, vector<long long>, greater<long long>> q;
        
        for(long long i = 0; i < n; i++)
            q.push(arr[i]);
        
        long long result = 0;
        long long x;
        while(q.size() > 1) {
            
            x = q.top(); q.pop();
            x += q.top(); q.pop();
            
            result += x;
            q.push(x);
        }
        
        return result;
    }
};