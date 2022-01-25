// Stickler Thief 
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int inc = arr[0];
        int exc = 0;
        for(int i = 1; i < n; i++)
        {
            int temp_inc = exc + arr[i];
            int temp_exc = max(inc, exc);
            
            exc = temp_exc;
            inc = temp_inc;
        }
        
        return max(inc, exc);
        
    }
};