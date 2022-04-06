// Minimum sum
// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        
        sort(arr, arr+n);
        
        string result = "";
        int carry = 0, sm;
        
        for(int i = n - 1; i >= 0; i -= 2) {
            
            sm = carry + arr[i];
            if(i - 1 >= 0)
                sm += arr[i - 1];
            
            result += '0' + (sm % 10);
            carry = sm / 10;
        }
        
        if(carry > 0)
            result += '0' + carry;
            
        while(result.size() > 1 && result.back() == '0')
            result.pop_back();
        
        reverse(result.begin(), result.end());
        return result;
    }
};