// Check Power of 2                                    
// NOTE: 0 is not power of 2
// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#

class Solution{
    public:
    bool isPowerofTwo(long long n){
        
        return n and !(n & (n - 1));
    }
};