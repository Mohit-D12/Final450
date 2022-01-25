// Product array puzzle - vector where v[i] contains product of all elements except a[i]
// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    
    //Approach 1: storing pro_left and pro_right to find the ans
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        
        vector<long long int> res(n);
        long long int pro = 1;
        
        for(int i = 0; i < n; i++)
        {
            res[i] = pro;
            pro *= nums[i];
        }
        
        pro = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            res[i] *= pro;
            pro *= nums[i];
        }
        
        return res;
    }

    //Approach 2: based on number of 0s in the original array
    vector<long long int> productExceptSelf2(vector<long long int>& nums, int n) {
       
        int count = 0;
        for(auto i:nums)
        {
            if (i == 0)
                count++;
            if (count == 2)
                break;
        }
        
        if(count == 0)
        {
            vector<long long int> res;
            long long int pro = 1;
            for(auto i:nums)
                pro *= i;
            
            for(auto i:nums)
                res.push_back(pro/i);
            
            return res;
        }
        else if(count == 1)
        {
            vector<long long int> res(n, 0);
            int x;
            long long int pro = 1;
            for(int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {
                    x = i;
                    continue;
                }
                pro *= nums[i];
            }
            res[x] = pro;
            return res;
        }   
        else
        {
            vector<long long int> res(n, 0);
            return res;
        }
    }
};
