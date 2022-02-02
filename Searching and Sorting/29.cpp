// Smallest factorial number
// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int calc(int n) //find number of trailing 0s in n!
    {
        int base = 5;
        int count = 0;
        
        while(n >= base)
        {
            count += n / base;
            base *= 5;
        }
        
        return count;
    }
    public:
        int findNum(int n)
        {
            int s = 5, e = 40010; // value of res at n = 10000
            int res = -1;
            
            int mid = s + (e - s)/2;
            
            while(s <= e)
            {
                if(calc(mid) >= n)
                {
                    res = mid;
                    e = mid - 1;
                }
                else
                    s = mid + 1;
                
                mid = s + (e - s)/2;
            }
            
            return res;
        }
};