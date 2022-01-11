// Count total set bits from 1 to N
// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        
        if(n <= 1)
            return n;
        
        int result = 0;
        int bits = floor(log(n)/log(2));
        int p = 1 << bits;
        
        
        result = bits * (p/2);
        return result + (n-p+1) + countSetBits(n-p);
    }
9
    int countSetBitsApproach2(int n)
    {

    // Ignore 0 as all the bits are unset
    n++;

    // To store the powers of 2
    int powerOf2 = 2;

    // To store the result, it is initialized with n/2 because the count of set least significant bits in the integers from 1 to n is n/2
    int cnt = n / 2;

    // Loop for every bit required to represent n
    while (powerOf2 <= n) 
    {

        // Total count of pairs of 0s and 1s
        int totalPairs = n / powerOf2;

        // totalPairs/2 gives the complete count of the pairs of 1s Multiplying it with the current power of 2 will give the count of 1s in the current bit
        cnt += (totalPairs / 2) * powerOf2;

        // If the count of pairs was odd then add the remaining 1s which could not be groupped together
        cnt += (totalPairs & 1) ? (n % powerOf2) : 0;

        // Next power of 2
        powerOf2 <<= 1;
    }

    return cnt;
    }
};