// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    int find_pivot(vector<int>& nums, int n)
    {
        int s = 0, e = n-1;
        int mid = s + (e - s)/2;
        while (s < e)
        {
            if(nums[mid] >= nums[0])
                s  = mid + 1;
            else
                e = mid;

            mid = s + (e - s)/2;
        }
        return e;
    }

    int binary_search(vector<int>& nums, int s, int e, int target)
    {
        int mid = s + (e - s)/2;

        while(s <= e)
        {
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                s = mid + 1;
            else
                e = mid - 1;
            
            mid = s + (e - s)/2;
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int pivot = find_pivot(nums, n);

        if(nums[0] == target)
            return 0;
        
        if (nums[0] < target)
            return binary_search(nums, pivot+1, n-1, target);
        
        return binary_search(nums, 1, pivot-1, target);
    }
};