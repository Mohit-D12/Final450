// Sort by Set Bit Count
// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    static int get_set_bits(int n)
    {
        int count = 0;
        while(n > 0)
        {
            n = n & (n - 1);
            count++;
        }
        
        return count;
    }
    
    static bool compare(int a, int b)
    {
        if (get_set_bits(a) > get_set_bits(b))
            return true;
        
        return false;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr+n, compare);
    }
};