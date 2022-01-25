// Zero Sum Subarrays
// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    long long findSubarray(vector<long long> arr, int n ) {
        //code here
        unordered_map<long long, long long> s;
        long long temp = 0, ans = 0;
        
        
        for(int i:arr)
        {
            temp += i;
            if (temp == 0)
                ans++;
                
            if(s.find(temp) != s.end())
            {
                ans += s[temp];
                s[temp]++;
            }
            else
                s[temp] = 1;
            
        }
        
        return ans;
    }
};