// Count triplets with sum smaller than X
// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr, arr+n);
	    int ans = 0;
	    
	    for(int i = 0; i < n - 2; i++)
	    {
	        int j = i + 1; 
	        int k = n - 1;
	        
	        while( j < k )
	        {
	            if(arr[i] + arr[j] + arr[k] >= sum)
	                k--;
	            else
	            {
	                ans += k - j;
	                j++;
	            }
	        }
	    }
	    
	    return ans;
	}
		 

};