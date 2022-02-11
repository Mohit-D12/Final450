// Overlapping Intervals
// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1#

#include<bits/stdc++.h>
using namespace std;

class Solution {

  public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result = {intervals[0]};
        
        for(auto interval: intervals)
        {
            int x = result.size() - 1;
            
            if(result[x][1] < interval[0])
            {
                vector<int> r(interval);
                result.push_back(r);
            }   
            else
                result[x][1] = max(result[x][1], interval[1]);
        }
        
        return result;
    }
};