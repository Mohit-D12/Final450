// Max values in all windows of size k
// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/

#include<bits/stdc++.h>
using namespace std;

class Solution_EFFICIENT_WITH_DEQUE {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        deque<int> q;
        vector<int> result(n - k + 1);
        
        
        for(int i = 0; i < n; i++) {
            
            while(q.size() && arr[q.back()] < arr[i])
                q.pop_back();
            
            q.push_back(i);
            
            if(i >= k - 1) {
                
                while(q.size() && q.front() < i - k + 1)
                    q.pop_front();
                    
                result[i - k + 1] = arr[q.front()];
            }
        }
        
        return result;
    }
};

class Solution_HEAP {

    public:
    vector<int> maxSlidingWindow_usingHeap(vector<int>& nums, int k) {
    
        vector<int> ans;
        int n = nums.size();
        priority_queue<pair<int,int>> maxHeap;
        
        for (int i = 0; i < n; i++) {
            maxHeap.push(make_pair(nums[i], i));
            if (maxHeap.size() < k)
                continue;
            
            while (!maxHeap.empty() && (maxHeap.top()).second < i-(k-1)) {
                maxHeap.pop();
            }
            ans.push_back((maxHeap.top()).first);
        }
        return ans;
    }
};
