// Next smaller element
// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/#

#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> s;
        s.push(-1);
        vector<int> result(n);
        
        for(int i = n - 1; i >= 0; i--) {
            
            while(s.size() && s.top() >= arr[i])
                s.pop();
            
            result[i] = s.top();
            s.push(arr[i]);
        }
        
        return result;
    } 
};
