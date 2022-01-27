// Allocate minimum number of pages
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    bool is_possible(int* a, int n, int m, int key)
    {
        int count = 0;
        int s = 0;
        
        for(int i = 0; i < n; i++)
        {
            if (a[i] > key)
                return false;
                
            if (s + a[i] > key)
            {
                s = a[i];
                count++;
            }
            else
                s += a[i];
            
            if(count == m)
                return false;
        }
        
        return true;
    }

    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N < M)
            return -1;
            
        int s = 0, e = 0;
        for(int i = 0; i < N; i++){
            e += A[i];
            s = max(s, A[i]);
        }
        int mid = s + (e - s)/2;
        int ans = -1;
        
        while(s <= e)
        {
            // cout << "tag " << mid << ' ' << is_possible(A, N, M, mid) << endl;
            if(is_possible(A, N, M, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
            
            mid = s + (e - s)/2;
        }
        
        return ans;
    }
};