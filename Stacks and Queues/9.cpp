// Next Greater Element
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> v(n);
        stack<long long> s;
        s.push(-1);
        
        for(int i = n-1; i >= 0; i--)
        {
            if(s.top() > arr[i] || s.top() == -1)
            {
                v[i] = s.top();
                s.push(arr[i]);
            }
            else
            {
                while(s.top() <= arr[i] && s.top() != -1)
                    s.pop();
                
                v[i] = s.top();
                s.push(arr[i]);
            }
        }
        
        return v;
    }
};