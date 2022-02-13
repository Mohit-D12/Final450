// Partition Equal Subset Sum
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sm = 0;
        for(int i = 0; i < N; i++)
            sm += arr[i];
        
        if(sm & 1)
            return 0;
        sm = sm/2;
        
        bool** dp = new bool*[N];
        for(int i = 0; i < N; i++)
            dp[i] = new bool[sm+1];
        
        
        // first row
        for(int i = 0; i <= sm; i++)
            dp[0][i] = false;
        if(arr[0] <= sm)
            dp[0][arr[0]] = true;
        //first column
        for(int i = 0; i < N; i++)
            dp[i][0] = true;
        
        for(int i = 1; i < N; i++)
            for(int j = 1; j <= sm; j++)
                dp[i][j] = (dp[i-1][j]) || ((j >= arr[i]) && (dp[i-1][j - arr[i]]));
        
        
        return dp[N-1][sm];
    }
};