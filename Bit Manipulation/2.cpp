// Non Repeating Numbers
// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x = 0;
        vector<int>::iterator ptr;
        
        for(ptr = nums.begin(); ptr != nums.end(); ptr++)
            x ^= *ptr;
            
        int msb = log(x) / log(2);
        int mask = 1 << msb;
        
        vector<int> result(2, 0);
        
        for(ptr = nums.begin(); ptr != nums.end(); ptr++)
            if(*ptr & mask)
                result[0] ^= *ptr;
            else
                result[1] ^= *ptr;
        
        sort(result.begin(), result.end());
        return result;
        
    }
};