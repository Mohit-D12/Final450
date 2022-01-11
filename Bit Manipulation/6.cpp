// Find Position of MSB
// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1#

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        
        if ( !n or (n & (n-1)) )
            return -1;
            
        return log(n)/log(2) + 1;
    }
};